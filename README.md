**DengFOC平衡车项目**是基于simplefoc开源的[平衡车项目](https://github.com/simplefoc/Arduino-FOC-balancer)，进行结构改进和效果优化后应用在我开源的[DengFOC](https://gitee.com/link?target=https%3A%2F%2Fgithub.com%2FToanTech%2FDeng-s-foc-controller)双路无刷电机驱动器上的DengFOC配套项目。

**项目完全开源，你可以根据本Github内容自行白嫖，或者，支持一下灯哥的辛勤劳作，进入灯哥开源TB店购买DengFOC平衡车套件，一键配齐。**
# 一、安装过程
## 1.所需元器件

1. DengsFOC V3（你可以在TB搜索灯哥开源进入店铺购买，或根据DengFOC开源仓库的开源资料自制）
1. 2204云台电机*2
1. AS5600编码器*2
1. MPU6050陀螺仪*1
## 2.接线过程
| 零件 | 接线位置 |
| --- | --- |
| 2204云台电机 | DengFoc M0位置 |
| 2204云台电机 | DengFoc M1位置 |
| AS5600 | SDA0,SCL0,3V3,GND |
| AS5600 | SDA1,SCL1,3V3,GND |
| MPU6050 | SDA1,SCL1,3V3,GND |
| 电池以及电源开关线 | DengFoc 电源端子 |

<div align=center><img src="https://cdn.nlark.com/yuque/0/2022/jpeg/29556705/1658726142877-9f28c112-e2d8-4a41-9511-c2e7cdb84b38.jpeg#clientId=ud7e80494-18d0-4&crop=0&crop=0&crop=1&crop=1&from=drop&id=u8959390c&margin=%5Bobject%20Object%5D&name=jxk.jpg&originHeight=804&originWidth=1306&originalType=binary&ratio=1&rotation=0&showTitle=false&size=670792&status=done&style=none&taskId=u713ed618-7299-4a36-8b2e-979d1fbe761&title=" width="50%"></div>
如果你是自行DIY，那么按照上面的接线表格将线接入DengFOC即可；如果你是采用在 [灯哥开源 淘宝店](https://gitee.com/link?target=https%3A%2F%2Fshop564514875.taobao.com%2F) 购买的平衡车套件，那么你会得到**如下所示配套线材**。
配套接线材料：

- AS5600编码器接线套装 一头是杜邦端子，接有一根黑线GND，一根红线VCC，一根白线SDA，一根黄线SCL，另一端是4p端子。

<div align=center><img src="https://cdn.nlark.com/yuque/0/2022/jpeg/29556705/1658732386903-efa15b67-b70c-4941-ba27-01360ba33d21.jpeg#clientId=ud7e80494-18d0-4&crop=0&crop=0&crop=1&crop=1&from=drop&height=687&id=ue6ac9170&margin=%5Bobject%20Object%5D&name=82a44fa94f239555ce58f6244a66ed0.jpg&originHeight=2749&originWidth=3024&originalType=binary&ratio=1&rotation=0&showTitle=false&size=2515828&status=done&style=none&taskId=u3d4ff099-0d40-4e27-978a-aae4d85ed18&title=&width=756" width="50%"></div>

- MPU6050接线端子套装  两头是4p端子，接有一根黑线GND，一根红线VCC，一根白线SDA，一根黄线SCL。

<div align=center><img src="https://cdn.nlark.com/yuque/0/2022/jpeg/29556705/1659197290859-baca7588-2321-479d-89b7-cdc072274528.jpeg?x-oss-process=image/auto-orient,1#clientId=uf7e0ba99-3f45-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=4303&id=uba0cd8b5&margin=%5Bobject%20Object%5D&name=55b902b26434df53b378a106f7e21df.jpg&originHeight=4032&originWidth=3024&originalType=binary&ratio=1&rotation=270&showTitle=false&size=7156971&status=done&style=none&taskId=ud7eea850-74a5-4281-ac20-234a3e275eb&title=&width=3227" width="50%"></div>

- 电源接线开关
## 3.组装步骤

- AS5600编码器红色线代表VCC，黑色线代表GND，黄线代表SCL，白色代表SDA。将端子一端的4p端子连接到AS5600对应的端子上。同时将接线端子的另外一端杜邦壳接到DengFoc的排针对应的接口上。

<div align=center><img src="https://cdn.nlark.com/yuque/0/2022/jpeg/29556705/1658733147161-a7114c72-7787-4d8f-87a1-c37bba2b9bae.jpeg?x-oss-process=image#clientId=ud7e80494-18d0-4&crop=0&crop=0&crop=1&crop=1&from=drop&height=1344&id=ueb92c346&margin=%5Bobject%20Object%5D&name=6cc40a7b3f8229de27552fabf990182.jpg&originHeight=4032&originWidth=3024&originalType=binary&ratio=1&rotation=90&showTitle=false&size=7463437&status=done&style=none&taskId=u128e01dd-f329-4b82-90e6-5e01f79f15b&title=&width=1008" width="50%"></div>

- MPU6050陀螺仪接线端子红色线代表VCC，黑色线代表GND，黄色线代表SCL，白色线代表SDA，接线端子一端MPU6050连接，一端与AS5600编码器相连。

<div align=center><img src="https://cdn.nlark.com/yuque/0/2022/png/29556705/1659198691486-75ec0549-a6d6-44f8-97a8-d58b49bc9780.png#clientId=uf7e0ba99-3f45-4&crop=0&crop=0&crop=1&crop=1&from=ui&id=u2da1725b&margin=%5Bobject%20Object%5D&name=f00aaf0db7439a537d264c95ea70ee6.png&originHeight=4032&originWidth=3024&originalType=binary&ratio=1&rotation=0&showTitle=false&size=5662012&status=done&style=none&taskId=ub0c5775b-dabf-43d5-acc4-88e31da14fa&title=" width="50%"></div>

- 电机1三线连接到DengFoc M0端从左到右分别对应白、黑、红，电机2连接到DengFoc M1端从左到右分别对应黑、白、红。

<div align=center><img src="https://cdn.nlark.com/yuque/0/2022/png/29556705/1658723033386-90efd5e1-e491-4202-9ba1-e3fe11924ddb.png#clientId=ud7e80494-18d0-4&crop=0&crop=0&crop=1&crop=1&from=drop&id=uf93a2687&margin=%5Bobject%20Object%5D&name=c6f966013554d56d4bc7ed013528ae2.png&originHeight=483&originWidth=690&originalType=binary&ratio=1&rotation=0&showTitle=false&size=872754&status=done&style=none&taskId=u8ad56c5a-f2b9-4a58-bdcd-ab91f25e82e&title=" width="50%"></div>

详细安装过程可以观看安装视频，视频中有关于车体各部分的详细安装步骤以及连线步骤。
<div align=center><img src="https://cdn.nlark.com/yuque/0/2022/jpeg/29556705/1658826979606-d28aae9b-3c3a-4bd8-9e1a-65967c301e7e.jpeg#clientId=ud7e80494-18d0-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=404&id=u55c836cf&margin=%5Bobject%20Object%5D&name=5522f0eed69760f91982180e10e3c55.jpg&originHeight=807&originWidth=1901&originalType=binary&ratio=1&rotation=0&showTitle=false&size=192884&status=done&style=none&taskId=u81d2a174-34f0-4fe1-8281-3d1be218a05&title=&width=951" width="50%"></div>
# 二、调试过程

- 烧写平衡车代码例程，上电之后等待陀螺仪校准，以及电机校准。
- 看平衡车是否能够自稳。
- 微信扫描下图二维码，进入小程序。

<div align=center><img src="https://cdn.nlark.com/yuque/0/2022/jpeg/29556705/1658995945709-b32ce5d3-e0bf-45f8-902d-4778f4c084ea.jpeg#clientId=uf132aef5-784f-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=206&id=u9cf80577&margin=%5Bobject%20Object%5D&name=gh_34733bbc52a9_258%20%281%29.jpg&originHeight=258&originWidth=258&originalType=binary&ratio=1&rotation=0&showTitle=false&size=44452&status=done&style=none&taskId=uf258815f-b7d0-48fa-bfa2-301326425df&title=&width=206.4" width="50%"></div>

- 进入小程序页面，看蓝牙是否连接成功。小程序页面图如下所示。

<div align=center><img src="https://cdn.nlark.com/yuque/0/2022/png/29556705/1658981439669-79171f8d-fdcb-4359-b592-9b70f6e3f5ec.png#clientId=uf132aef5-784f-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=570&id=ue829420b&margin=%5Bobject%20Object%5D&name=image.png&originHeight=712&originWidth=400&originalType=binary&ratio=1&rotation=0&showTitle=false&size=22876&status=done&style=none&taskId=ue86b0408-a97e-45b2-b2ea-91151953fad&title=&width=320" width="50%"></div>


- 接着移动摇杆看功能是否正常。
- 如果想自己DIY小车控制速度，可以在例程中对小车控制参数进行修改。
