## **IP路由基础：**

IP路由涉及将<font color=yellow>网络流量</font>从其源头<font color=yellow>传送</font>到目的地，跨越多个网络设备的过程。此过程依赖于路由表，用于确定数据包达到其预定目的地的最佳路径。

#### IP地址    網絡掩碼

分為網絡部分（3字節）和主機部分（1字節）

網絡部分就是<mark>網段</mark>    主機部分就是<mark>該網段下的設備編號</mark>

#### IP地址的分類

![](/Users/jolin/Pictures/md.pic.library/ip分類.png) 

### **1. 目的地和子网掩码：**

ip地址範圍0.0.0.0～255.255.255.255

- **子网掩码：** 子网掩码用于识别IP地址的网络部分和主机部分，通常以255.255.255.0的格式表示，并有助于确定<font color=red>网络边界</font>。

### **2. 路由协议：**

- **直连网络（直连路由）：** 这些是到达路由器接口的直连网络的路由。路由器因为连接到这些网络而知道它们。

- **静态路由：** 静态路由是由网络管理员手动配置的。它们指定数据包遵循的固定路径。

- **动态路由：** 动态路由协议允许路由器交换它们所知道的网络信息。常见的动态路由协议包括<font color=pink>OSPF、RIP、ISIS和BGP</font>。它们根据网络变化动态更新路由表。

### **3. 路由优先级（管理距离）：**

- **直连路由(Direct)：** 通常具有优先级0，因为它们是最可信赖的路由。

- **静态路由(Static)：** 通常设置为优先级60。

- **动态路由(Dynamic)：** 每个动态路由协议分配不同的优先级。例如，OSPF内部路由的优先级为<font color=yellow>10</font>，而OSPF外部路由的优先级为150。

- **BGP（边界网关协议）：** 通常具有最高优先级255。 //<font color=red>二进制中 -1 的Unsigned形式</font>

### **4. 路由开销：**  开销值指示使用特定路由的费用或权重。更低的开销值更受欢迎，因为它们表示更有效的路由。

> 静态路由开销为0；动态路由开销有差异

### **5. 下一跳：** 指的是在流量传输的链路中，遇到/经过的第一个/下一个三层设备的IP地址---->路由器等

### **6. 出接口：** 出接口指定数据包将要离开路由器的网络接口（例如以太网、串行）。

## 路由表组成成分

    Destination/mask    protocol    pre  Cost flags    nexthob    interface
      127.0.0.1/32       Direct      0    0    D     127.0.0.1    g0/0/1
        1.1.1.1/32       Static      60   0    D     100.0.0.1    g0/0/2

### **路由表选择：**

> IP路由表只能存放最优的路由

当有多个路径可用到达相同目的地时，路由表选择依赖于以下标准：

- **优先级：** 具有较低管理距离（较高优先级）的路由。

- **开销：** 较低开销的路由。

- **最长前缀匹配：** 选择具有最长子网掩码匹配的路由（子网掩码长度以位计算）。

#### **静态路由：**

静态路由是由网络管理员手动配置的，适用于<font color=hotpink>小型、稳定</font>的网络。它不适应网络变化，因此在动态环境中不太合适。

#### 配置命令：

ip route-static    +    目的网络地址    +    掩码    +    下一跳/出接口（建议使用下一跳）
 例如：ip route-static 20.1.1.0 255.255.255.0 12.1.1.2  

注意：下一跳必须在本路由器是可达的，否则就是一条无效路由

### 静态路由的应用：

- 负载分担：
  
  - 有多条的链路，有多条目的地相同路由，但是静态路由优先级一致，则为负载分担，此时走哪条链路均可
  
  - > 类似链路聚合

路由备份（浮动静态路由）

> 负载分担的恶变形，也类似于链路聚合

- 有多条目的地相同的路由，但是静态路由优先级不一致

> 优先级低的不会出现在路由表上，即
> 
> 优先级高的（主）出现故障，备份路由才会工作

ip route-static 20.1.1.0 255.255.255.0 21.1.1.2 preference 100   //通过修改静态路由的优先级值，从未实现主备链路的场景；当主链路挂了，则备用链路启用

#### **缺省路由（默认网关）：**

> 缺省路由就是目的地址和掩码全为0的特殊路由
> 如果报文的目的地址无法匹配路由表当中的任何一项，路由器将选择缺省路由来进行转发。

- 对于目的IP无法在路由表找到的数据帧，不至于丢包也是私网访问公网的方法

缺省路由（0.0.0.0/0）用于在路由表中没有特定匹配时。通常设置为互联网服务提供商（ISP）的网关，用于传出流量。 

---

> 距离矢量和链路状态的主要区别在于，距离矢量协议下路由器不知道该网络拓扑是什么样的，只知道目的地，如何去目的地
> 
> 而链路状态协议为了能使路由器了解网络拓扑，路由器、设备之间会有 邻居、领接关系（具体关系不同协议不同）

#### 现在我们先讨论动态-链路状态（Linke-state)路由协议

> OSPF    ISIS

## OPSF

#### 工作过程

１、建立邻居
２、相互交互路由信息
３、运行SPF算法，计算最优路由

#### 三个阶段

**邻居发现**：  
通过发送Hello报文形成邻居关系。  
**路由通告**：  
邻居间发送链路状态信息形成邻接关系。  
**路由计算**：  
根据最短路径算法算出路由表。

#### 基本概念

1. 区域

> 为了适应大型的网络，OSPF在AS(自治系统）上划分多个区域（100-200个路由器），每个OSPF路由器只维护所在区域的完整链路状态信息。  

- 从逻辑上分区，需要配置area id
  
  > 一定要有area 0 ----><mark>骨干区域</mark>
  > 
  > 其余为 <mark>非骨干区域</mark>
2. #### Router-id
- 在OSPF中路由器的唯一标识（可人为配置）
  
  > 类似物理上的mac地址
  
  - ##### Router ID选取规则
    
    （1）选举路由器Loopback接口上数值最高的IP地址  
    （2） 如果没有Loopback接口，在物理端口中选取IP地址最高的  
    
    - <u>Lookback接口是一类逻辑接口，状态永远是UP；选用lookback接口作router ID----> 稳定</u>
    
    （3）也可使用router-id任命指定的Router ID
3. #### 度量值---> cost
- cost=(100 Mbit/s) / 带宽 ---->向上取整 0.1--> 1

> FE接口----百兆
> 
> GE接口----千兆

- 每个接口都会有cost值，cost值累计/代数和

LSA（Link-state advertisement）

### OPSF报文类型

1. Hello报文，每个路由器都会周期（10/30s）发送用于发现OSPF /  维护邻居关系

2. Database Description（DD报文）描述本地的LSDB（路由器信息，网络拓扑等等）

> 两个路由器需要交换信息，他们首先交换的就是DD报文，用于检查哪些LSA是对方特有的，再发LAR请求报文------> 节省资源利用

3. LSR（request)  交换DD报文后比较所需LSA，向对方请求

4. LSU(update)用于发送对方所需要的LSA

5. LSACK 用来对收到的LSA作确认

## OSPF三大表

### 邻居表

> 路由器之间有连接，需要邻居表去记录连接
> 
> <mark>display ospf peer  brief</mark>     //查看邻居表

### LSDB表

> <mark>display ospf lsdb</mark>     //查看LSDB表

### OSPF路由表

和路由器路由表不同！

- ospf路由表根据链路数据库生成的到达不同目标网络的路由

- 路由器路由表是实际数据传输时的路由
  
  - 所以说在ospf中路由器根据ospf路由表选择实际 的路由，从而形成实际的路由表 

#### OSPF的两大状态

1. （2-way）邻居：只能是发送hello包建立邻居

2. （Full）邻接：最高登记的状态，在此状态下，可以交互LSA

##### 领接关系的建立（四个步骤）

1. 建立双向邻居关系（互发Hello报文）

2. 协商主/从关系 ------即DR/BDR

3. 交互LSDB

4. 同步LSDB

#### OSPF网络类型

> Broadcast Multiple Access
> 
> Non-Broadcast Multiple Access
> 
> Point to point (p2p)
> 
> Point to multiple point (p2mp)

![](/Users/jolin/Pictures/md.pic.library/OSPF网络类型.png)

#### DR / BDR

> BDR会监测DR，DR发生故障的时候，BDR会取代其位置

DR（指定路由器）：网络当中必须是有一个
BDR（备份指定路由器）：数量可以为0或者1
DRother（非指定路由器）：可以是0或者是多个，没有限制

DR的作用：减少邻接关系

DR和BDR是可以根所有的OSPF设备建立连接；DRother只能和DR和BDR建立邻接；于其他的DRother只能建立邻居关系

DR的优先级范围：0~255；默认为1；优先级是越大越优；

ABR（区域边界路由器）：一定是有多个区域，而且是包含骨干区域；
作用：传递区域间路由

ASBR（自治系统边界路由器）：该设备一定是运行多协议的，而且会产生外部路由（也就会把外部的路由信息引入到OSPF当中）；
作用：用于传递外部路由

OSPF配置：
ospf 1 router-id 1.1.1.1  //设置router id为1.1.1.1
 area 0.0.0.0   //设置区域ID
  network 10.1.1.0 0.0.0.255 <mark>//反掩码---255.255.255.255-掩码</mark>----->發布網段都需要輸入反掩碼--->範圍
  network 12.1.1.0 0.0.0.255 ／／发布接口的路由信息

查看OSPF邻居关系的配置命令：
display ospf peer  brief 

---

## ISIS

 １、ISIS是属于链路状态协议的一种，集成的ISIS可以工作TCP／ＩＰ和OSI网络模型

　　地址格式：８～2０Bytes
　　地址组成：area id+system id+sel  //system id始终是占6个字节，sel占1个字节；剩余的就都是area id

2、设备分类
   ISIS设备可以分为L１、L２、L１－２
　　　默认属于：L1-2路由器

3、邻居建立

> 分为L1邻居和L2邻居

  L1设备，必须和相同area id的设备建立邻居
  L2设备，可以与相同或者不同的area id的设备建立邻居    

- L1-2设备可以同时建立L1邻居和L2邻居关系

4、区域划分：

- L1与L2之间通过L1-2连接
  
  - L2和L1-2处于骨干区域
  
  - L1 处于非骨干区域

//配置命令

> 配置前輸入‘sy‘+’tab’ 進入'system-view'回車命名設備才能開始配置

isis 100  //设置进程号；进程号范围<1-65535>
 network-entity 49.0001.0000.0000.0002.00 //配置net地址

interface GigabitEthernet0/0/0
 isis enable 100  //发布该接口的路由信息；注意：enable后面加的是进程号；该进程号要与前面isis所配置的一致

修改设备等级（两种方式）：

1、在全局下修改
isis 1
 is-level level-1

2、在接口下修改
interface GigabitEthernet0/0/0
 isis circuit-level level-2  

查看邻居关系的命令：
display isis peer 

---

---

# BGP

> 边界网关协议（控制不同区域的流量路由）
> 
> 保护信息安全
> 
> > 直连状态下设备间可以随意互访，获取信息
> > 
> > 而BGP只会交换路由信息

#### BGP的对等体关系（邻居关系）：

IBGP：AS号相同
EBGP：AS号不同

#### 对等体的建立过程

1. 建立TCP连接
   
   > 发送TCP SYN，回复TCP ACK确认

2. 互发open报文，协商BGP协议

3. 互发keepalive报文（建立成功标志）随后周期发送keepalive报文维持对等体关系

4. 互发update报文

### BGP报文类型

| 报文名称           | 作用                        | 发送时间                                        |
| -------------- | ------------------------- | ------------------------------------------- |
| open           | 协商BGP参数，建立对等体关系           | BGP TCP连接建立成功之后                             |
| update         | 发送BGP路由更新                 | BGP对等体关系建立之后有路由需要发送或路 由变化时向对等体发送Update报文    |
| notification   | 报告错误信息，中止对等体关系            | 当BGP在运行中发现错误时，发送Notification 报文将错误通告给BGP对等体 |
| keepalive      | 标志对等体建立，维持BGP对等体关系        | 收到对方的keepalive报文后周期发送                       |
| router-refresh | 用于在改变路由策略后请求对等体重新发送路 由信息。 | 当路由策略发生变化时，触发请求对等体重新<br/>通告路由               |

BGP邻居建立配置：
bgp 200  //设置BGP的AS号
peer+目的地址+目的AS号
例子： peer 12.1.1.1 as-number 100 

BGP发布路由配置：
方式1：通过network的方式发布；可以单独把一条路由进行发布
配置：
bgp 200
  network 192.168.1.1 255.255.255.255  //发布的路由必须和全局路由表一致

方式2：通过import的方式发布；可以把引入的协议的路由一起发布
bgp 100
  import-route static  //将静态路由进行发布

---

## PPP

PPP是工作在（串行链路上）
    例如：光纤、ATM、FR等网络中
    PPPOE(把PPP的功能应用到以太网中)
    使得以太网也可以像PPP一样，支持认证、授权、审计、分配IP地址等功能

    保障两个点之间安全可靠地传输数据

### PPP中的认证协议

**认证方式：**

- **PAP（Password Authentication Protocol）：** PAP使用简单的明文密码进行认证。在PAP认证中，客户端将明文密码发送到认证服务器，然后认证服务器验证密码的正确性。这意味着密码以明文形式传输，存在安全风险。
- **CHAP（Challenge Handshake Authentication Protocol）：** CHAP使用挑战-响应机制进行认证。在CHAP认证中，认证服务器向客户端发送一个挑战，客户端使用挑战和密码计算响应，然后将响应发送回认证服务器。由于挑战和响应是基于密码计算的，密码本身不会在网络上传输。

————————————————————————————
PPP配置
R1和R2   (R1是运营商，（认证方））
              (R2是客户设备，（被认证方））

- R1配置(Pos接口)
  
      <mark>ppp authentication-mode chap       (pap)</mark>          //配置认证，认证类型为：CHAP(可以选择PAP和CHAP)
      ip address 12.1.1.2 30                      配置接口IP地址
        (一般：PPP链路是点到点两台设备，不需要过多的IP地址，30位可以节省IP地址)
  
    可选(例如：客户端没有IP地址，可以分配IP地址给客户端)
  
       remote address pool A     //配置地址池
         (ip pool A参考DHCP地址池配置)
  
     ip pool A
  
        network 12.1.1.0 mask 24     //创建地址池，并且设置地址范围12.1.1.0/24网段
              (如果配置了认证，例如CHAP或者PAP认证方，需要配置AAA用户)
  
    aaa
     local-user A password cipher 1234
     local-user A service-type ppp

---

- R2配置
  
      ppp chap user A     //设置用户名A,用于CHAP认证
      ppp chap password simple 1234    //设置密码：1234明文显示，用于CHAP认证
      ip address 12.1.1.1 24       //配置接口通信地址
                   (也可以不配置接口地址，通过认证方获取)
      (ip address ppp-negotiate )        //用于协商IP地址，通过R1

---

### PPPoE

> 配置在以太网接口

**工作原理：** PPPoE连接通常涉及到两个主要组件：PPPoE客户端和PPPoE服务器。客户端通常是用户的路由器或计算机，而服务器通常由互联网服务提供商（ISP）提供。

- 当用户设备启动连接时，PPPoE客户端发送认证请求到ISP的PPPoE服务器。
- 认证请求通常包括提供用户名和密码，以验证用户身份。
- 一旦用户通过认证，PPPoE连接建立，客户端和服务器之间可以互相通信。
- 数据流量在客户端和服务器之间通过PPP协议进行封装和传输。

> 以太网数据帧的length/type 为<mark>0x8864</mark> 表示承载着PPPoE发现阶段的报文
> 
>                                                     <mark> 0x8863</mark>                             <mark>會話階段的報文</mark>

---

### DHCP（动态主机配置协议）

原理： 通过配置dhcp服务器给主机自动分配ip地址；

优点： 
          1.可以动态的获取ip地址及网络参数
          2.减少工程师的配置量，减少ip地址冲突
          3.动态修改设置网络参数（ip地址租期，dns，主机ip地址静态）

DHCP结构=客户端（68端口号）+ 服务器（67端口号）

#### 分配IP的规则/优先级

1. mac地址绑定的ip

2. 已使用过的IP

3. 空闲的ip

4. 超过租期的IP

5. 有冲突的ip

##### DHCP工作工程：（客户端----服务器）

1.发现阶段：   客户端向服务器，发送 DHCP <font color=pink>discover 报文</font><mark>（广播）</mark>，用于请求ip地址
2.提供阶段：   服务器向客户端，回复DHCP <font color=red>Offer报文</font><mark>（单播）</mark>，用于提供ip地址
3.选择阶段：   客户端会根据所收到offer报文中，向服务器发送<font color=red>DHCP request报文</font>，选择使用最先接收的offer报文中的ip地址
4.确认阶段：   服务器向客户端确认，发送<font color=red>DHCP ack报文</font> ，告诉客户端该ip地址可以正常使用；

客户端在50%租期时间会向服务器发送续租请求

如没有收到回复，会在85%时间向服务器再次发送<mark>DHCP discover</mark>报文

### dhcp配置：

①全局地址池
   [DHCP-Server]   dhcp  enable           //开启DHCP服务功能

   [DHCP-Server]   ip pool KS1              //创建IP地址池 命名为 KS1
                             gateway-list 192.168.1.254       //设置网关ip地址为192.168.1.254 
                             network 192.168.1.0 mask 255.255.255.0   //创建地址池可分配的网段（192.168.1.0 掩码24）
                  dns-list 114.114.114.114            //设置dns服务器的ip地址
                  static-bind ip-address 192.168.1.100 mac-address 5489-98fc-1526 
                 //配置主机固定分配ip地址为192.168.1.100，与该主机的mac地址进行绑定

            int g 0/0/0           //进入接口视图
            ip address 192.168.1.254 24   //在接口配置ip地址，该地址必须和地址池的网关一致
            dhcp select global    //dhcp应用全局地址池

②接口地址池
      [DHCP-Server]   dhcp  enable           //开启DHCP服务功能

                int g 0/0/1 //进入接口视图
                 ip address 192.168.2.254 24       //配置ip地址，该地址是作为网关，并且设备分配ip地址的网段
                  dhcp select interface             //dhcp应用接口地址池
                  dhcp server dns-list 8.8.8.8      //设置dns服务器的ip地址
                  dhcp server static-bind ip-address 192.168.2.200 mac-address 5489-9844-691c 
                                                   //配置主机固定分配ip地址为192.168.2.200，与该主机的mac地址进行绑定

---

## AAA---网络安全管理机制

> authentication标识                authorization授权                accounting收费
> 
> 验证用户是否可获得访问权    授权用户可以使用哪些服务  记录使用时长/收费
> 
> <mark>AAA常见网络架构中包括用户、NAS（Network Access Server）、AAA服务器（AAAServer）</mark>

### AAA原理与配置

原理：实现对网络设备进行认证，授权，计费；

   1.认证：对用于进行身份的认证，才能接入网络
   2.授权：对不同用户进行等级限制，或者资源访问权限
   3.计费：用于登入后进行时间的计费

#### AAA 常用的协议是RADIUS

RADIUS使用UDP（UserDatagram Protocol）作为传输协议，并规定UDP端口1812、1813分别作为认证、计费端口，具有良好的实时性；

- ## RADIUS客户端与服务器间的消息流程如下：

1.当用户接入网络时，用户发起连接请求，向RADIUS客户端（即NAS）发送用户名和密码。

2.RADIUS客户端向RADIUS服务器发送包含用户名和密码信息的<mark>认证请求报文</mark>。

3.RADIUS服务器接收到合法的请求后，完成认证，并把所需的用户授权信息返回给客户端；对于非法的请求，RADIUS服务器返回认证失败的信息给客户端。

4.RADIUS客户端通知用户认证是否成功。

5.RADIUS客户端根据接收到的认证结果接入/拒绝用户。如果允许用户接入，则RADIUS客户端向RADIUS服务器发送计费开始请求报文。

6.RADIUS服务器返回计费开始响应报文，并开始计费。

7.用户开始访问网络资源。

8.当用户不再想要访问网络资源时，用户发起下线请求，请求停止访问网络资源。

9.RADIUS客户端向RADIUS服务器提交计费结束请求报文。

10.RADIUS服务器返回计费结束响应报文，并停止计费。

11.RADIUS客户端通知用户访问结束，用户结束访问网络资源。

![](/Users/jolin/Library/Application%20Support/marktext/images/2023-10-30-19-03-08-image.png)

配置：
aaa    //进入AAA视图
 local-user huawei password cipher   huawei@123   //创建本地用户名 huawei 密码为huawei@123

 local-user huawei <mark>privilege level</mark> 15                 //配置用户权限为等级15    <mark>（范围0-15，一般配3+到15）</mark> 
 local-user huawei service-type telnet       //配置支持的服务类型为telnet

> 服务类型：` 
> 
> | 8021x    |           | 802.1x user              |
> | -------- | --------- | ------------------------ |
> | bind     | <br>      | Bind authentication user |
> | ftp      | FTP user  | <br>                     |
> | http     | Http user | <br>                     |
> | PPP      | PPP user  | <br>                     |
> | ssh      | SSH user  | <br>                     |
> | ssvpn    | <br>      | Sslypn user              |
> | • telnet | Telnet    | user                     |
> | terminal | <br>      | Terminal user            |
> | web      | <br>      | Web authentication user  |
> | x25-pad  | <br>      | X25-pad user`            |

     user-interface vty 0 4         //进入虚拟接口 vty 0 4 

     authentication-mode aaa    //绑定认证模式为aaa

    <R1>telnet  23.1.1.3                  //测试远程R3，并且输入名字和密码

---

## ACL (access control list)

##### ACL的原理与配置：

原理：通过一系列的语句对数据报文进行匹配，结合路由策略和策略路由进行放行和过滤

应用：通过permit（允许）和deny（过滤）<mark>语句</mark>进行对流量处理，根据规则由小到大进行逐一匹配；

ACL分类：
 ①基础acl：只能匹配流量的源ip进行匹配，范围（acl 2000-2999）
 ②高级acl：可以根据流量的五元组匹配（源目ip地址，源目端口号，协议号），范围（acl 3000-3999）

匹配流量规则（通配符）
“0”表示严格匹配，通配符对应的数据是固定不变的
“1”表示任意匹配，通配符对应的数据是任意改变的

匹配奇数地址：匹配192.168.1.0   24 网段的所有奇数地址----------192.168.1.1  0.0.0.254
（最后一位固定为1，2^n+1=奇数）

匹配偶数地址：匹配192.168.1.0   24 网段的所有偶数地址----------192.168.1.0  0.0.0.254
（最后一位固定为1，2^n+0=偶数）

匹配地址案例： 
             192.168.1.1   0.0.0.0   //匹配单独的唯一 一个地址
             192.168.1.1  0.0.0.255   //匹配192.168.1.0    24网段的地址
             192.168.1.1  0.0.0.254    //匹配192.168.1.0    24网段的所有奇数地址
             192.168.1.0  0.0.0.254    //匹配192.168.1.0    24网段的所有偶数地址

配置：
acl number 2000  
        rule 5 deny source 192.168.1.1 0     //配置规则5，把所有来源的ip地址为192.168.1.1的流量全部过滤

interface GigabitEthernet0/0/0
 ip address 192.168.1.254 255.255.255.0 
 traffic-filter inbound acl 2000

acl number 3000  
 rule 5 deny ip source 192.168.1.1 0 destination 192.168.2.3 0    
                                  //规则5，过滤源ip为192.168.1.1 目的ip地址为192.168.2.3的流量
 rule 10 permit ip         //规则10，放行所有流量

interface GigabitEthernet0/0/0
    ip address 192.168.1.254 255.255.255.0 
    traffic-filter inbound acl 3000

补充： 华为设备acl规则，默认是放行所有流量

---

## NAT

NAT（网络地址转换）

原理：通过该NAT技术，实现私网地址转换公网地址，进行私网设备访问公网设备功能

应用：

①静态NAT： 一个私有地址只能转换一个公有地址，一对一的映射转换，需要额外占用公网，浪费公网ip地址使用；
          缺陷： 1.配置繁琐，需要手工一对一配置
                     2.浪费公网ip地址，不太适用于园区部署

配置：
int g 0/0/1   //在连接公网的出接口
nat static  global  122.1.2.11 inside  192.168.1.1      //配置静态nat映射表项，将私网地址192.168.1.1 映射为公网地址122.1.2.11

②动态NAT：可以创建<mark>私网，公网地址池</mark>，根据公网地址池空闲的地址实现动态NAT的转换，不需要人为一对一绑定，较灵活；
          缺点：1.在大型网络中，由于公网地址池的接口数量少，导致批量pc映射时失败，丢包的问题，不稳定；

配置：
acl number 2000  
   <mark> rule 5 permit source 192.168.1.0 0.0.0.255</mark>    //创建私网地址池 为 192.168.1.0  24 网段

 nat address-group 1 122.1.2.11 122.1.2.20    //创建公网地址池为122.1.2.11-20 

int  g    0/0/1
    ip address 122.1.2.1 255.255.255.0 
  <mark>  nat outbound</mark> 2000 address-group 1 no-pat       //在出接口调用绑定私网地址池和公网地址池

③动态NAPT：在动态NAT的基础上，增加<mark>port ID进行标识</mark>，实现N：1映射（多个私网地址共同转换为一个公网地址），在大型网络中映射时，相比动态NAT稳定，不会出现公网不够用映射失败的问题，基于端口号映射；
          缺点：需要额外使用公网地址作为映射，至少消耗两个公网地址，成本高；

配置：
acl number 2000  
    rule 5 permit source 192.168.1.0 0.0.0.255    //创建私网地址池 为 192.168.1.0  24 网段

 nat address-group 1 122.1.2.11 122.1.2.11  //创建公网地址池为122.1.2.11

int  g    0/0/1
    ip address 122.1.2.1 255.255.255.0 
    nat outbound 2000 address-group 1     //在出接口调用绑定私网地址池和公网地址池

④Easy IP：实现原理和NAPT相同，同时转换IP地址、传输层端口，区别在于Easy IP没有地址池的概念，只用接口地址作为NAT转换的公有地址即可（最常使用的配置）；

配置：

acl number 2000  
    rule 5 permit source 192.168.1.0 0.0.0.255    //创建私网地址池 为 192.168.1.0  24 网段

interface GigabitEthernet0/0/1
 ip address 122.1.2.1 255.255.255.0 
 nat outbound 2000                   //在出接口调用绑定私网地址池即可

以上四种nat都是基于数据包的源ip地址进行nat映射，公网访问私网时基于目的ip地址进行nat映射

⑤nat server：公网访问私网时，基于目的ip地址进行nat映射

int g 0/0/1      
    nat server global 122.1.2.100 inside 192.168.1.1   

display nat session all       //用于查看nat映射信息
