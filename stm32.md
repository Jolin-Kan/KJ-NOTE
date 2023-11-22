# STM32 F103C8T6



### GPIO 接口（general purpose input output)/IO口

#### 接口模式

![](/Users/jolin/Pictures/md.pic.library/GPIO結構.png)

Vdd/Vss保护二极管，Vdd高电压，Vss电压为零。

<mark>电压相对Vss判断大小，存在负电压</mark> 



- **浮空输入** 输入部分两个开关都不闭合

- **上拉输入** 输入部分闭合VDD--悬空默认高电平

- **下拉输入**  输入部分闭合VSS--悬空默认低电平

> 均是数字输入，<mark>均可读取引脚电平</mark> 



- **模拟输入**

相当于GPIO无效，直接接入<mark>片上外设</mark>即ADC

<font color=pinkviolet>施密特触发器</font>关闭

![](/Users/jolin/Pictures/md.pic.library/GPIO模拟输入.png)

- 施密特触发器的工作原理：

- 设定上下限阀值，只有突破阀值才会改变高低电平状态。保证电路的稳定。



- 开漏：上接pmos，高电平为高阻态，低电平接VSS

- 推挽： 下接nmos，高电平为VDD，低电平接VSS

- 输出接 P-mos      /        N-mos



- 复用-

> 实际就是输入由<mark>片上外设控制</mark>

![](/Users/jolin/Pictures/md.pic.library/开漏:推挽.png)
