# STM32 F103C8T6

### GPIO 接口（general purpose input output)/IO口

#### 接口模式

![](/Users/jolin/Pictures/md.pic.library/GPIO結構.png)

Vdd/Vss保护二极管，Vdd高电压，Vss电压为零。

<mark>电压相对Vss判断大小，存在负电压</mark> 

- **浮空输入  GPIO_MODE_IN_FLOATING** 输入部分两个开关都不闭合

- **上拉输入  GPIO_MODE_IPU** 输入部分闭合VDD--悬空默认高电平

- **下拉输入GPIO_MODE_IPD**  输入部分闭合VSS--悬空默认低电平

> 均是数字输入，<mark>均可读取引脚电平</mark> 

- **模拟输入** <font color=red> GPIO_MODE_AIN</font>

相当于GPIO无效，直接接入<mark>片上外设</mark>即ADC

<font color=pinkviolet>施密特触发器</font>关闭

![](/Users/jolin/Pictures/md.pic.library/GPIO模拟输入.png)

- 施密特触发器的工作原理：

- 设定上下限阀值，只有突破阀值才会改变高低电平状态。保证电路的稳定。

- **开漏 GPIO_MODE_OUT_OD**：上接pmos，高电平为高阻态，沒有驅動能力，低电平接VSS有驅動能力

- **推挽 GPIO_MODE_OUT_PP**： 下接nmos，高电平为VDD，低电平接VSS

- 输出接 P-mos      /        N-mos

- **复用开漏 GPIO_MODE_AF_OD**

- **复用推挽GPIO_MODE_AF_PP**

> 实际就是输入由<mark>片上外设控制</mark> 

![](/Users/jolin/Pictures/md.pic.library/开漏:推挽.png)

## 

驅動能力：以LED燈舉例，

高點平驅動：LED連結的藉口輸出高電平，正極接端口，高電平

低電平驅動，負極接接口

## 調用GPIO口初始化操作

```c
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitTypeDef.GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_X;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
 GPIO_Init(GPIOC, &GPIO_InitStructure);
```

- 第一步：使用RCC開啟GPIO時鐘

`RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);` 

- 第二步：使用`GPIO_Init`<mark>函數初始化GPIO</mark>

`GPIO_InitTypeDef GPIO_InitStructure;` 

`GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;` 
`GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;`
`GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz`

`GPIO_Init(GPIOC, &GPIO_InitStructure);`

> <mark>至此，初始化完成</mark> 

- 第三步：使用輸入輸出函數控制GPIO口

#### GPIO 的輸出函數

定義函數，定義一個結構體
初始化最後一步

- void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);

void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);

- void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
  void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
  void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
  void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);

SetBits 高電平
ResetBits 低電平
