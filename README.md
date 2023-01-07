**DengFOC平衡车项目**是基于simplefoc开源的[平衡车项目](https://github.com/simplefoc/Arduino-FOC-balancer)，进行结构改进和效果优化后应用在我开源的[DengFOC](https://gitee.com/link?target=https%3A%2F%2Fgithub.com%2FToanTech%2FDeng-s-foc-controller)双路无刷电机驱动器上的DengFOC配套项目。

![balancebot_gif](balancebot_gif.gif)

![get_down](get_down.gif)

**项目完全开源，你可以根据本Github内容自行白嫖，或者，支持一下灯哥的辛勤劳作，进入灯哥开源TB店购买DengFOC平衡车套件，一键配齐。**

[DengFOC 高敏捷自平衡车套件--链接猛击(进店后在 所有宝贝 处可找到)](https://shop564514875.taobao.com/)

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

<div align=center><img src="https://cdn.nlark.com/yuque/0/2023/png/29556705/1673063969912-11a8a680-f180-4ebb-81ec-b18d024a21ef.png#clientId=u8d4101ea-b663-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=474&id=u1d5cfb25&margin=%5Bobject%20Object%5D&name=5a6d1332478106ae221b35f65e3a17c.png&originHeight=592&originWidth=675&originalType=binary&ratio=1&rotation=0&showTitle=false&size=267736&status=done&style=none&taskId=ue39e4f0b-9bbb-4578-b9f7-c3e432f4b48&title=&width=540"></div>
如果你是自行DIY，那么按照上面的接线表格将线接入DengFOC即可；如果你是采用在 [灯哥开源 淘宝店](https://gitee.com/link?target=https%3A%2F%2Fshop564514875.taobao.com%2F) 购买的平衡车套件，那么你会得到**如下所示配套线材**。
配套接线材料：

- AS5600编码器接线套装 一头是杜邦端子，接有一根黑线GND，一根红线VCC，一根绿线SDA，一根黄线SCL，另一端是4p端子。

<div align=center><img src="https://cdn.nlark.com/yuque/0/2022/png/29556705/1659606811557-3fd58da0-efc3-47bb-8293-187b3dba2797.png#clientId=ud7d1bedd-68cc-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=472&id=ud6f2fa2b&margin=%5Bobject%20Object%5D&name=image.png&originHeight=590&originWidth=405&originalType=binary&ratio=1&rotation=0&showTitle=false&size=487494&status=done&style=none&taskId=ua1a533ac-4e7c-402c-87a8-6617679ca16&title=&width=324" width="50%"></div>

- MPU6050接线端子套装  两头是4p端子，接有一根黑线GND，一根红线VCC，一根绿线SDA，一根黄线SCL。

<div align=center><img src="https://cdn.nlark.com/yuque/0/2022/jpeg/29556705/1659610104755-9caaf847-7592-4d4c-8f3c-aff563ba711a.jpeg#clientId=u287477c3-79df-4&crop=0&crop=0&crop=1&crop=1&from=ui&height=424&id=u98924325&margin=%5Bobject%20Object%5D&name=7848c3111388e8f506677babe00cb7a.jpg&originHeight=1699&originWidth=869&originalType=binary&ratio=1&rotation=0&showTitle=false&size=305570&status=done&style=none&taskId=ufe021fad-3843-4d3b-8afb-30c4efa2d44&title=&width=217" width="50%">
</div>

- 电源接线开关
## 3.组装步骤

- AS5600编码器红色线代表VCC，黑色线代表GND，黄线代表SCL，绿色代表SDA。将端子一端的4p端子连接到AS5600对应的端子上。同时将接线端子的另外一端杜邦壳接到DengFoc的排针对应的接口上。

<div align=center><img src="https://cdn.nlark.com/yuque/0/2023/jpeg/29556705/1673070228910-5ec37fb2-88f8-4ca4-9b6e-8bc6071bbd81.jpeg#clientId=u8d4101ea-b663-4&crop=0&crop=0&crop=1&crop=1&from=ui&id=u5ff98f19&margin=%5Bobject%20Object%5D&name=8d53db30ccbb7898d689dc26b2101f0.jpg&originHeight=1785&originWidth=1304&originalType=binary&ratio=1&rotation=0&showTitle=false&size=545188&status=done&style=none&taskId=u7e8f8bbc-4599-456c-890e-add0cc46710&title=" width="50%"></div>

- MPU6050陀螺仪接线端子红色线代表VCC，黑色线代表GND，黄色线代表SCL，绿色线代表SDA，接线端子一端MPU6050连接，一端与AS5600编码器相连。

<div align=center><img src="https://cdn.nlark.com/yuque/0/2022/jpeg/29556705/1659609562931-85ea7041-3c20-42e5-81da-0655e9827b4a.jpeg#clientId=u287477c3-79df-4&crop=0&crop=0&crop=1&crop=1&from=paste&height=868&id=ud2af1925&margin=%5Bobject%20Object%5D&name=3f0d20d6fc2eff7e4885971b875ae95.jpg&originHeight=3472&originWidth=4624&originalType=binary&ratio=1&rotation=0&showTitle=false&size=1827206&status=done&style=none&taskId=uf12aff9d-1899-4b6e-8d65-8923398a93d&title=&width=1156" width="50%"></div>

- 电机1三线连接到DengFoc M0端旋转方向为cw，电机2连接到DengFoc M1端旋转方向为ccw。可通过串口查看旋转方向信息，若旋转方向不对可更换电机三相中任意两相顺序。


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
