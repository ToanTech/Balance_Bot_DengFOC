// 更换蓝牙库
#include <Arduino.h>
#include <SimpleFOC.h>
#include <MPU6050_tockn.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define gyroY_OFF -0.56

// 蓝牙参数
BLEServer *pServer = NULL;
BLECharacteristic * pTxCharacteristic;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint8_t txValue = 0;

#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" // UART service UUID
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

TwoWire I2Cone = TwoWire(0);
TwoWire I2Ctwo = TwoWire(1);
MagneticSensorI2C sensor0 = MagneticSensorI2C(AS5600_I2C);
MagneticSensorI2C sensor1 = MagneticSensorI2C(AS5600_I2C);


double acc2rotation(double x, double z);//for kalman
MPU6050 mpu6050(I2Ctwo);


BLDCMotor motor0 = BLDCMotor(7);
BLDCDriver3PWM driver0 = BLDCDriver3PWM(32,33,25,22);

BLDCMotor motor1 = BLDCMotor(7);
BLDCDriver3PWM driver1  = BLDCDriver3PWM(26,27,14,12);

// control algorithm parametersw
// stabilisation pid 自稳PID
//P0.55 I5.5 初始值0.5 5 
PIDController pid_stb{.P = 0.8, .I = 5.5, .D = 0, .ramp = 100000, .limit = 8}; 
// velocity pid 速度PID P初始值1.5
PIDController pid_vel{.P = 1.5, .I = 0, .D = 0.01, .ramp = 10000, .limit = _PI/4};
// velocity control filtering 速度控制滤波，滤波时间常数为0.07
LowPassFilter lpf_pitch_cmd{.Tf = 0.07};
// low pass filters for user commands - throttle and steering 油门和转向滤波
LowPassFilter lpf_throttle{.Tf = 0.5}; //初始值0.5
LowPassFilter lpf_steering{.Tf = 0.1};//初始值0.1

String resStr;
String chipId;
String readString;

float steering = 0;
float throttle = 0;
float new_steering;
float new_throttle;
// max_throttle数值可能需要更改
float max_throttle = 50; // 初始值20 rad/s 
float max_steering = 0.8; //  1V
float Offset_parameters = -9.3; //偏置参数
int Checkcomma; //判断是否含有逗号分隔


Commander commander = Commander(Serial);
void cntStab(char* cmd) {  commander.pid(&pid_stb, cmd);}
void cntMove(char* cmd) {  commander.pid(&pid_vel, cmd);}
void lpfPitch(char* cmd) {  commander.lpf(&lpf_pitch_cmd, cmd);}
void lpfSteering(char* cmd) {  commander.lpf(&lpf_steering, cmd);}
void lpfThrottle(char* cmd) {  commander.lpf(&lpf_throttle, cmd);}

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};



class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string rxValue = pCharacteristic->getValue();

      if (rxValue.length() > 0) {
        Serial.print("Received Value: ");
        // 打印蓝牙接收信息
        for (int i = 0; i < rxValue.length(); i++){
//          Serial.print(rxValue[i]);
          resStr += rxValue[i];
        }
        Checkcomma = resStr.indexOf(',');
        if(Checkcomma != -1){
          new_steering = resStr.substring(0,Checkcomma).toInt();
          new_throttle = resStr.substring(Checkcomma+1,resStr.length()).toInt();
          steering = max_steering * new_steering/50;
          throttle = max_throttle * -new_throttle/50;
//          Serial.print("new_steering:");
//          Serial.print(new_steering);
//          Serial.print("\t");
//          Serial.print("new_throttle:");
//          Serial.print(new_throttle);
//          Serial.print("Y:");
//          Serial.print(throttle);
//          Serial.print("\t");
//          Serial.print("X:");
//          Serial.println(steering);
        }
        else{
          steering = 0;
          throttle = 0;
        }
        // 清空数据准备下次接收
        resStr = "";
      }
    }
};

void setup(){
    Serial.begin(115200);
    _delay(750);

    chipId = String((uint32_t)ESP.getEfuseMac(), HEX);
    chipId.toUpperCase();
    Serial.println(chipId);
    //  初始化蓝牙 蓝牙名称
    BLEDevice::init("Blue Control");

    // 开启一个蓝牙服务
    pServer = BLEDevice::createServer();
    pServer->setCallbacks(new MyServerCallbacks());

    BLEService *pService = pServer->createService(SERVICE_UUID);

    pTxCharacteristic = pService->createCharacteristic(
                        CHARACTERISTIC_UUID_TX,
                        BLECharacteristic::PROPERTY_NOTIFY
                      );

    pTxCharacteristic->addDescriptor(new BLE2902());

    BLECharacteristic * pRxCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID_RX,
        BLECharacteristic::PROPERTY_WRITE
                                          );

    pRxCharacteristic->setCallbacks(new MyCallbacks());

    pService->start();

    pServer->getAdvertising()->start();
    Serial.println("Waiting a client connection to notify...");

    I2Cone.begin(19,18, 400000UL); 
    I2Ctwo.begin(23,5, 400000UL);
  
    sensor0.init(&I2Cone);
    sensor1.init(&I2Ctwo);

    mpu6050.begin();
    mpu6050.calcGyroOffsets(true);

    // link the motor to the sensor
    motor0.linkSensor(&sensor0);
    motor1.linkSensor(&sensor1);

     // 速度环PID参数
    motor1.PID_velocity.P = 0.05;
    motor1.PID_velocity.I = 1;
    motor1.PID_velocity.D = 0;

    motor0.PID_velocity.P = 0.05;
    motor0.PID_velocity.I = 1;
    motor0.PID_velocity.D = 0;

    motor0.voltage_sensor_align = 6;
    driver0.voltage_power_supply = 8;
    driver0.init();
    motor0.linkDriver(&driver0);
    motor1.voltage_sensor_align = 6;
    driver1.voltage_power_supply = 8;
    driver1.init();
    motor1.linkDriver(&driver1);

    motor0.torque_controller = TorqueControlType::voltage;
    motor1.torque_controller = TorqueControlType::voltage;
    motor0.controller = MotionControlType::torque;
    motor1.controller = MotionControlType::torque;

    // enable monitoring
    motor1.useMonitoring(Serial);
    motor0.useMonitoring(Serial);

    // initialise motor
    motor1.init();
    motor0.init();
    // align encoder and start FOC
    motor1.initFOC();
    motor0.initFOC();

    commander.add('A', cntStab, "pid stab");
    commander.add('B', cntMove, "pid vel");
    commander.add('C', lpfThrottle, "lpf vel command");
    commander.add('D', lpfPitch, "lpf throttle");
    commander.add('E', lpfSteering, "lpf steering");

}

void loop(){
    while (Serial.available() > 0) {
    if (deviceConnected) {
      delay(3);
      readString += Serial.read();
      pTxCharacteristic->setValue(chipId.c_str());
      pTxCharacteristic->notify();
      Serial.println(chipId);

    }
  }
    // 未连接
    if (!deviceConnected && oldDeviceConnected) {
    delay(500); 
    pServer->startAdvertising(); // restart advertising
    Serial.println("start advertising");
    oldDeviceConnected = deviceConnected;
    }
  // 连接成功
    if (deviceConnected && !oldDeviceConnected) {
    oldDeviceConnected = deviceConnected;
    }
    motor1.loopFOC();
    motor0.loopFOC();
    motor1.move();
    motor0.move();

    mpu6050.update();
    double mpu_pitch = mpu6050.getAngleY();// tockn的getangle，通过一阶置信计算
    float target_pitch = lpf_pitch_cmd(pid_vel((motor0.shaft_velocity + motor1.shaft_velocity) / 2 - lpf_throttle(throttle)));
//    Serial.println(target_pitch);
    float voltage_control = pid_stb(Offset_parameters - mpu_pitch + target_pitch);
    float steering_adj = lpf_steering(steering);
  
    motor0.target = voltage_control - steering_adj;
    motor1.target = voltage_control + steering_adj;
    commander.run();

}
