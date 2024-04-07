# Note for Front-end

## HTML5

> HTML     *hyper text markup language*
> 
> SO <font color=#ff0000>label</font> makes up html. Every elements of html are label 

#### XHTML & HTML4 & HTML5

> has a little differences in grammar 
> 
> <mark>XHTML ---> XML & HTML</mark>

---

<img title="图片title" src="file:///Users/jolin/Pictures/md.pic.library/前端三件套.png" alt="图片alt" width="208" data-align="center">

## DOCTYPE statement

<!DOCTYPE>

 is a necessary part of a web which is at the very beginning of the document(before all the labels) -----> <font color=#ff0000>***avoid the wired mode of the browser.***</font>

---

## HTML has <font color=#ff0000>five</font> basic structure

### 1. <html></html>

> it is a double label which tells the document is the HTML type.
> 
> it also limits the <font size=10>*starting*</font> and ending points of the document

### 2.<head></head>

> head label is used to define the head of the document,also including the various info or attribute. <font color=#ff0000>But is for browser rather than user</font>

### 3.<body></body>

> the body label defines the body of the document. It covers all the elements of the document including image, linked, video,table and so on <u>****which are directly displayed for user***.*</u>

### 4.<title></title>

> 1.it can rename the title of the doc
> 
> 2.it is displayed on the<font color=# 0000 ff> $status$ $bar$</font> of the web
> 
> 3.Title label must be in the head label ----> <font color=#ff0000>***name is also the info of the DOC***</font>
> 
> > a title label has positive effect on SEO

### 5. <meta> | is a single label !!!!

> meta label is used to claim a web DOC's attribute of key words.
> 
> meta label is in the head label like title label does.

## <meta> properties

| property    | statement                                                                                           |
| ----------- | --------------------------------------------------------------------------------------------------- |
| content     | 必須的，定義與http-equive or name 屬性相關聯的元信息                                                                |
| http-equive | 把content屬性關聯到HTTP頭部。取值有：content-type,expires,refresh,<font color=red>set-cookie</font> (用於設定網頁是否緩存) |
| name        | 把content屬性關聯到一個名稱。取值有：author,description,keywords,generator,revised...                              |
| scheme      | 定義 用於翻譯content屬性值的格式                                                                                |
| charset     | 定義字符編碼格式（UTF-8//gb2312）                                                                             |

```html
<mate http-equive='refresh'content='5'/>
<--5s刷新一次web --> 
```

---

## The basic structure of html like:

> ```html
> <!DOCTYPE html>
> <html lang = "en" >
>     <head>
>             <meta charset = "utf-8"> //"utf-8"means kinds of encoding format
>             <title>test</title>
>     <head>
>     <body>
>     </body>
> </html>    
> ```

## Title label ---->  `<h1>****</h1>`

Title has six level; 1~6

```html
<body>
<h1>title 1</h1>
<h2>title 2</h2>
.....

<h6>title 6</h6>
</body>
```

> we can change the location of title by changing its attribute of  <font color=red>align</font>.
> 
> ```html
>     <h1 align="center"> title center </h1>
> ```

- <font color=purple>align属于HTML4的属性，建议使用CSS实现此类功能</font>

![](/Users/jolin/Pictures/md.pic.library/title%20label.png)

## paragraph  / break / horizon line --- label

1. paragraph label <p></p>
   
   > double label 

2. break label <br/>

```html
<p>I am a paragraph label</p>
<p> I want to show you about the effect
of break label <br/> in the paragraph label</p>
```

![](/Users/jolin/Pictures/md.pic.library/<p>:<br>.png)

<font color=pink>break label ----> line break during a paragraph</font>

3.Horizon line <hr/>

the attribute of <font color=blue>color width size align</font> is changeable

> size also means height 
> 
> width size ----> XXX px (pixel)

```html
<hr color="pink" width ="300px" size="10px" align="right">
```

> * align only has two adjusting mode (left/right)
> 
> * because it defaults to be in center.

## image label -----> single label

has five attributes we can change

- src : source road  

- alt: the img's name. when the img fail to display, browser will show alt name.

- title: the tips about the img when mouse float on the img will show.

    ![](/Users/jolin/Pictures/md.pic.library/img%20alt%20title.png)

- width / height : we usually change only one.

- > If we do not modify according to the image scale, it will cause stretching and distortion of the image

- we can also add some margin between img
  
  > there is two ways
  > 
  > css & inside edit 

```html
.image {
    margin-right: 10px; /* 添加右侧间隔 */
}
```

```html
<img src="image1.jpg" style="margin-right: 10px;">
<img src="image2.jpg" style="margin-right: 10px;">
<img src="image3.jpg" style="margin-right: 10px;">
```

Attribute of <font color=red>style</font> 

## The path of img

1. Absolute path
   
   > the path 

2. Relative path
   
   > 源码文件和图片文件在同一路径下
   > 
   > > sub-level: '/'
   > > 
   > > Parent-level: '../'
   > > 
   > > Sibling-level: './' (Omitted)可省略

3. Internet path
   
   > the path in the internet router 

---

## <a> 超連結標籤

- 連結的種類

- 內部/外部連結

- <mark>錨點連結</mark>

> 適用於內容較多的同一頁面內的內容之間跳轉

    <mark>任意設置了id的元素都可作為錨點連結</mark> ---->利用`#`連結

`<a herf="#IdName"> </a>`

- 定義下載連結,    herf屬性後添加`download` 

- `<a herf="img.jpg" download>下載照片</a>`

```html
<a herf='URL'>link text</a>
<a herf='URL'>
    <img src='' >
</a>
```

- 超連結文本可以是圖片/文本/

> 日後利用CSS可以更改顯示的樣式

---

## 文本標籤

##### 描述性文本標籤

- 有別與之前所提及的段落<p>標籤

> 段落標籤承載的是一段話，而文本標籤單純承載<mark>词汇</mark>

### 描述性/定義-文本标签的类型：

```html
    <em></em>     emphasis
    <b></b>    bold
    <i></i>    italic
    <strong></strong> like bold
    <del></del>    delete line
    <span></span>    meaningless
    <p>my favouoite camara brand is <b>Nikon</b></p>
    <big>
   <small>    可嵌套，一級一級放大/縮小字號
```

`sub & sup`

```html
<p>
    我正在對<sup>sup標籤</sup>和<sub>sub標籤</sub>做測試查看他們的效果<br>
    一般用於數學公式：<br>
    f<sub>2</sub>(x)=x<sup>2</sup>+4x
</p>
```

<div>
<p>
    我正在對<sup>sup標籤</sup>和<sub>sub標籤</sub>做測試查看他們的效果<br>
    一般用於數學公式：<br>
    f<sub>2</sub>(x)=x<sup>2</sup>+4x
</p>
</div>

![](/Users/jolin/Pictures/md.pic.library/文本标签效果.png)

- 如圖，文本標籤還可以嵌套在<p>中使用

#### 定義輸出文本-(都是雙標籤)

- <code>     顯示原代碼 

- <pre>       顯示預設代碼樣式

- <tt>          打印機字體

- <kbf>        鍵盤字體

- <dfn>        表示定義的術語

- <var>        表示變量字體

- <samp>      表示代碼範例

#### 定義插入和刪除文本

<ins>/<del>

> 就是下劃線和中間橫線

#### 定義文本方向

<bdo dir=<mark>'rtl/ltr'</mark> XXXX</bdo>

BDO用於段落中的短語和句子，不能跨段落使用

BDI

用於內容方向位置的文本，自動調整

---

## 列表標籤

> order list & disorder list
> 
> <ol>    <ul>

### 有序列表和無序列表的實現以及<font color=blue>嵌套</font>

```html
<ol type="I">
        <li>first</li>
        <li>
            second
            <ul type="circle">
                <li>inside first</li>
                <li>inside second</li>
            </ul>
        </li>
        <li>third</li>
    </ol>
```

<div>
<ol type="I">
        <li>first</li>
        <li>
            second
            <ul type="circle">
                <li>inside first</li>
                <li>inside second</li>
            </ul>
        </li>
        <li>third</li>
    </ol>
</div>

### Type

##### 有序列表：

- 1---->數字

- a---->小寫字母

- A---->大寫字母

- i---->小寫羅馬數字

- I---->大寫羅馬數字

#### 無序列表

- disc    
  
  - circle
    
    - square

- none

> 快捷輸入：ol>li*3

### 表格標籤

- table    <tr>行    <td>列

`table>tr*5>td*5`

```htmnl
<stable>        //2x2表格
        <tr>
            <td>1</td>
            <td>2</td>
        </tr>
        <tr>
            <td>3</td>
            <td>4</td>
        </tr>
    </stable>
```

#### 表格的合并

- 水平合并-->colspan-->列与列之间

- 垂直合并-->rowspan-->行与行之间

> 合并的时候保留第一个单元格，删除其余单元格
> 
> 保留的标准为<mark>“左上”</mark>

`<td colspan="3">`

---

##### <main> <span> <section> <article> <div>

> sec強調的是內容上的不同，但<font color=blue>之間有關聯/連續性</font>
> 
> art 總的強調<mark>結構上</mark>的不同，內容並無關聯

---

### 进度/刻度信息

<progress>

<meter> 

> value    min    max    low    high    optimum    form

#### Form表单

用于前后端信息传递/处理

表单组成部分：

- 表单标签
  
  ```htmnl
     <form action=" "  name=" " method=" get｜post">
  ```
  
  - 表单标签的属性
  
  - action存储服务器的地址（后端（）
  
  - method是指数据传输方式，get可以查看数据URL，post不行

- 表单域

- 表单按钮

```htmml
 <form action=""  name="" method=""> //表单标签
        <input type="text">    //表单域（输入区域）
        <input typr='password'> //输入效果显示为小圆点

<input type="submit" value=‘log in’>//表单按钮---可用input type=‘submit’实现
 //同时，使用input制作按钮是，可以使用value属性替换文本

        <button>log </button>
    </form>
```

- <div>
  <form action=""  name="" method=""> 
          <input type="text">   
          <input typr='password'>
  
  <input type="submit" value=‘log in’>
  
          <button>log </button>
      </form>
  
  </div>

- 表单包含控件和容器，容器用做储存控件

- 控件就是按钮，输入框等 

- <font color=red>設計🔘單選/多選按鈕</font>

- radio類型表示單選，但是每一個`input`　<mark>內的name屬性要相同</mark> 

```html
Type:<input type="radio" name="a" value="1"/>K-pop
    <input type="radio" name="a" value="2"/>J-pop
   <input type="radio" name="a" value="3"/>Canton-pop
```

<div>
<form action="#">
    <h3>checkbox是多选radio是单选</h3>
    <p>menmbership:<input type="text" value=""/></p>
    <p>Order0-num:<input type="text" value=""/></p>
 <p>
    Type:<input type="radio" name="a" value="1"/>K-pop
    <input type="radio" name="a" value="2"/>J-pop
   <input type="radio" name="a" value="3"/>Canton-pop
</p>
    <p><input type="submit" value="submit"></p>
</form>
</div>

- 設計<mark>選擇框</mark>

> <mark>在<select>標籤內放置<option>標籤
> 
> <mark><option>標籤可以分組，放在<optgroup>標籤下，同時<optgroup label=“ ">label 屬性可命名</mark>

<div>
<form action="">
    <h3>selection list</h3>
    <p>choose your city:select <select name="city">
        <optgroup label="guangdong">
            <option value="guangzhou">guangzhou</option>
            <option value="shenzhen">shenzhen</option>
        </optgroup>
        <optgroup label="shandong">
            <option value="qingdao">qingdao</option>
            <option value="huaifang">huaifang</option>
        </optgroup>
    </select></p>
    <p><input type="submit" value="submit"></p>
</form>

</div>

---

#### 文本域

<input type=' '>

有多种type，text / password /file ······

input還有一種是大容量輸入

```html
 <form>
        <table width="600" align="center">
            <tr>
                <td>留言方式1</td>
                <td>留言方式2</td>
            </tr>
            <tr>
                <td><textarea name="message1" cols="60" rows="10" placeholder="在这里输入您的信息"></textarea></td>
                <td><textarea name="message2" cols="60" rows="10" disabled="disabled" placeholder="在这里输入您的信息"></textarea></td>
            </tr>
        </table>
    </form>
```

<div>
 <form>
        <table width="600" align="center">
            <tr>
                <td>留言方式1</td>
                <td>留言方式2</td>
            </tr>
            <tr>
                <td><textarea name="message1" cols="60" rows="10" placeholder="在这里输入您的信息"></textarea></td>
                <td><textarea name="message2" cols="60" rows="10" disabled="disabled" placeholder="在这里输入您的信息"></textarea></td>
            </tr>
        </table>
    </form>
</div>

小細節：屬性 placeholder=' '    內容灰度表示，提示用戶

### fieldset

 可将表单内的相关元素分组。<mark>legend（圖例，定義字段慾的標題） 是fieldset的标题</mark>

<fieldset>

```html
<form>
  <fieldset>
    <legend>健康信息</legend>
    身高：<input type="text" />
    体重：<input type="text" />
  </fieldset>
</form>
```

<div>
<form>
  <fieldset>
    <legend>健康信息</legend>
    身高：<input type="text" />
    体重：<input type="text" />
  </fieldset>
</form>
</div>

### 元素的分類

> 在H5中有更豐富的元素分類
> 
> 但適應初學者，粗略分為兩類

| 塊級元素            | 行內塊級元素（內聯元素）     |
| --------------- | ---------------- |
| 獨佔一行，自上而下排列     | 只佔自身大小，從左至右排列    |
| 可設置width/height | width/height屬性無效 |
| 塊級可以包含塊級和行內元素   | 行內元素不能包含塊級元素     |

- 塊級元素

> p    hr    table    form    div    ul    ol

- 行內元素

> a    b    em    strong    span

- 行內塊級元素（可調節width/height）

> button <mark>/區分bottom/ </mark>      img    input

文档流是文档中可显示对象在排列时所占用的位置/空间

例如：块元素自上而下摆放，内联元素，从左到右摆放

标准流里面的限制非常多，导致很多页面效果无法实现

脱离文档流

使⼀个元素脱离标准文档流有三种方式

1. 浮动
2. 绝对定位
3. 固定定位

---

H5的新元素

> nav    header    section    aside    footer    article

就是替換`<div id=' '>`

div是標籤容器，用於區分不同的結構

而新增使用<mark>語義化標籤使代 碼更加簡潔</mark>

---

## CSS3

CSS概念

CSS（Cascading Style Sheets）层叠样式表，又叫级联样式表，简称样式表

CSS文件后缀名为`.css`

CSS用于HTML文档中元素样式的定义

### 為什麼需要CSS

使用css的唯一目的就是让网页具有美观一致的页面

### 語法

CSS 规则由两个主要的部分构成：选择器，以及一条或多条声明（样式）

每条声明由一个<mark>属性</mark>和一个<mark>值</mark>组成

属性（property）是希望设置的样式属性（style attribute）。每个属性有一个值。属性和值被冒号分开

```css
<style>
    h1{
        color: blue;
        font-size: 12px;
    }
</style>
```

---

- 利用html設計網絡頁面

- <font color=purple>注重框架，盡可能使用語義化label，盡少使用`div`  </font>

- <font color=blue>保證SEO，框架的嵌套盡可能少，一般為一級</font>

- <font color=red>先不考慮視覺效果，注重邏輯、框架</font> 

---

#### CSS的使用

- 行内样式（元素）

- ```html
  <p style="background: orange; font-size: 24px;">CSS<p>
  ```

- 内部样式（html文件内设置）

- ```html
  <head>
      <style> 
         h1 { 
             background: red; 
         } 
      </style>
  </head>
  <h1>
  header one
  </h1>
  ```

- 外部样式（类似项目）

- > <mark>在html文件目录下插入CSS文件</mark>
  > 
  > <font color=purple>同时需要在html文件头部添加CSS链接link</font>

```html
<link rel="stylesheet" type="text/css" href="xxx.css">
```

---

### CSS實現的關鍵----選擇器

#### 全局選擇器

一般用於初始化 `*{ /**/ }`

#### 元素选择器

适用于所有同类元素 `div{ /**/ }` 

#### 类选择器

用<mark>class属性</mark>区分，比元素选择器更灵活

`.box{ /**/ }     <div class="box"></div> ` 

#### ID选择器

类似类选择器，不多赘述

#### 合并选择器

`选择器1，选择器2...{/**/ }` 

### 关系选择器：

### 伪选择器：    更细化、灵活选择对象

查书 P 173

---

## CSS盒子模型

概念

所有HTML元素可以看作盒子，在CSS中，"box model"这一术语是用来设计和布局时使用

CSS盒模型本质上是一个盒子，封装周围的HTML元素，它包括：

外边距（margin），边框（border），补白（padding）（内部填充，透明），和实际内容（content）

![](/Users/jolin/Pictures/md.pic.library/盒子模型.png)

### Background- 背景属性

## 文檔流的缺點：

- 高矮不齊，以底邊對齊

- 空格折疊
  
  - 利用`white-space` 屬性
  
  - 1. **`normal`：** 默认值。合并连续的空白字符，换行符被当作空格处理。文本在有换行符的地方换行，文本中的空格和换行都会被压缩成单个空格。
       
       `white-space: normal;`
    
    2. **`nowrap`：** 不允许文本换行。文本将在同一行上显示，即使它超过了容器的宽度。
       
       `white-space: nowrap;`
    
    3. **`pre`：** 保留空白字符，但是不允许文本自动换行。空格和换行符将按照它们的原始样子显示。
       
       `white-space: pre;`
    
    4. **`pre-wrap`：** 保留空白字符，并允许文本自动换行。
       
       `white-space: pre-wrap;`
    
    5. **`pre-line`：** 保留空白字符，允许文本自动换行，并且忽略多个空白字符。`white-space: pre-line;` 

- 元素間無空隙

### Float属性

#### Float属性的副作用

- 父级元素高度坍塌

- 后续元素会受到影响

#### 清除浮动方法

1. 为父级元素设定高度

2. Overflow：父级元素添加overflow：  `overflow:hidden;  clear：both;` 

3. 受影响的元素添加clear ： `clear:both;`

4. 伪对象：
   
   `.container::after{`
   
   `overflow:hidden;`
   
   `display:block;`  //display屬性：---> block / inline / inline-block
   
   `clear:both;`       // clear属性：清楚浮动
   
   `}` 

#### 定位：position

- 相对定位-relative

- 绝对定位-absolute
  
  - 脱离文档流,同时会创建一个层级相互覆盖。<mark>每个`position:absolute` 都是一個層級</mark>

- 固定定位-fixed 
  
  - 固定，不隨頁面滾動而變化位置

> 其中，绝对定位和固定定位会脱离文档流
> 
> **温馨提示** 
> 
> 设置定位之后，相对定位和绝对定位他是相对于具有定位的父级元素进行位置调整，如果<mark>父级元素</mark>不存在定位，则继续向上逐级寻找，直到顶层文档

---

## 圆角

使用 CSS3 `border-radius` 属性，你可以给任何元素制作 "圆角"

`border-radius` 属性，可以使用以下规则：

1. 四个值: 第一个值为左上角，第二个值为右上角，第三个值为右下角，第四个值为左下角
2. 三个值: 第一个值为左上角, 第二个值为右上角和左下角，第三个值为右下角
3. 两个值: 第一个值为左上角与右下角，第二个值为右上角与左下角
4. 一个值： 四个圆角值相同

`border-radius` 的子属性

- `border-top-right-radius` 

- `border-bottom-right-radius` 

- `border-top-left-radius` 

- `border-bottom-left-radius` 

### 陰影

---

#### 圖像的居中：

```css

```

---

### CSS 属性技巧用法 归纳总结

#### 逐帧动画

- 利用`steps()`属性

- `Steps(n,arg)` 
  
  - arg : `junmp-start` `jump-end` `jump-both` `jump-none` 
  
  - 若不填写arg默认 `jump-start`

- `steps()` 的本质其实是把动画分为 n 个时刻，依次显示，<font color = red>而不是线性显示完整动画 </font> 

#### 具体使用案例：

- 比如秒针的一秒一格转动
  
  - steps（60，junmp-none）

- 若想实时同步，只需要调整最开始的角度即可。

---

## Flip 动画

---

# Javascript

#### JavaScript输出方式

JavaScript有很多种输出方式，都可以让我们更直观的看到程序运行的结果

```js
/* 在浏览器中弹出一个对话框,然后把要输出的内容展示出来,
alert都是把要输出的内容首先转换为字符串然后在输出的*/
alert("要输出的内容");

document.write("要输出的内容"); 

// 在控制台输出内容
console.log("要输出的内容");
```

#### 數據類型：

- number

- string

- boolean

- object

- null

- undefined
  
  - ```js
    console.log(num)
    //輸出undefined
    //變量提升，會將num這個變量提升，等價如下
    
    var num;
    console.log(num)
    ```

#### JS的运算符

- 算术运算符

- 逻辑运算符（同C）

- 字符串运算符

- 算位运算符
  
  - `>>` right shift；填充的数字由右移后最左边的数值决定
  
  - `>>>` Unsigned right shift；填充的数值一律为`0`  

- 赋值运算符（包含位运算）

- 比较运算符

- 特殊运算符
  
  - `,` 逗号运算符，计算两个表达式，返回第二个表达式的值
  
  - ```js
    for(var i=0,j=10;i<=10;i++,j--)
        a[i,j]=i+j;
    ·····
    ·····
    //增加运算任务
    ```
  
  - `?:` 唯一的三元运算符
  
  - ```js
    var status = age >= 18 ? "adult" : "minor";
    //当 age 大于等于 18 的时候，将“adult”赋值给 status；
    //否则将“minor”赋值给 status。
    ```

---

## Js数组方法

#### Sort( <font color = yellow>compareFunction</font>)

- 比较函数 `compareFunction` 的作用是指定数组元素的排序顺序。当 `compareFunction` 返回值为负数时，表示 `a` 应该排在 `b` 的前面，即升序排序；当返回值为零时，表示 `a` 和 `b` 相等，它们的相对顺序不变；当返回值为正数时，表示 `a` 应该排在 `b` 的后面，即降序排序。

- ```js
  sort((a,b) => a-b); //表示升序 
  ```
  
  - a,b为默认排序；若a < b, a - b < 0,a在b前;若a=b, a - b = 0,不变，a仍在b前;若a > b, a-b > 0,b在a的前面

- ```js
  同理：降序
  sort((a,b)=> b-a);
  ```

---

### this

> this是函数的自由变量

#### 三种判断方法

1. 通过`new`创建. `this`指向創建對象
   
   ```js
   function Person(name)
   {
       this.name=name;
   }
   const person = new Person('Alice');
   console.log(person.name);//輸出 ‘Alice’
   ```

2. 显式绑定，通过`call`/`bind`/`apply`方法添加
   
   ```js
   const liu = {name:‘张飞’}
   function person(){
       console.log(this.name);
   };
   
   person.call(liu); //输出 ‘张飞’
   ```

3. 隐式绑定，在对象中创建
   
   ```js
   const zhang = {
       name:'张飞';
       sayhello(){
           console.log(`你好,${this.name}`);
       }
   }
   zhang.sayhello(); //输出 ‘张飞’
   ```

### this 的简单使用

- 创建一个有三个方法的 `calculator` 对象：
  
  - `read()` 提示输入两个值，并将其保存为对象属性，属性名分别为 `a` 和 `b`。
  - `sum()` 返回保存的值的和。
  - `mul()` 将保存的值相乘并返回计算结果。

```js
let calculator = {
  // ……你的代码……
  sum() {
    return this.a + this.b;
  },

  mul() {
    return this.a * this.b;
  },

  read() {
    this.a = +prompt('a?', 0); 
    this.b = +prompt('b?', 0);
  }
};

calculator.read();
alert( calculator.sum() );
alert( calculator.mul() ); 
```

> `prompt`是一个`WebApi` 指示浏览器显示一个对话框，其中有一个可选的信息，提示用户输入一些文本，并等待用户提交文本或取消对话框。

```js
prompt()
prompt(message)
prompt(message, defaultValue)
```

#### Promise

> 是一种构造函数，用于异步编程

### 基本构成

- promise本体

- then方法（对promise内部操作反馈）

### 基础格式

```js
let p = new Promise((resolve,reject)=>{
    if(success)
    {
       resolve(value); //value传入resolve，在then中使用（在then中以value使用）
    }
    if(fail)
    {
      reject(reason);
    }
});


p.then(
    value => {};
    reason => {};   
)
```

### Async函数

```js
async function main(){
    //1.return 一个非promise类型的数据
    return 555; //ret 就为 555
    //2. return promise类型且状态为成功
    return p = new Promise((resolve,reject)=>{
        resolve('ok');
    })
    //ret 是一个状态为成功的promise类型
    //3. return promise类型且状态为失败
    return p = new Promise((resolve,reject)=>{
        reject('Error');
    })
    //ret 是一个状态为失败的promise类型
}
let ret = main();
console.log(ret);
```

### Await表达式

> Await只有在Async函数内有效，否则报错

- await 右侧为promise以外的数据类型：
  
  - 原样返回

- await 右侧为promise类型
  
  - promise状态为成功
    
    - 返回promise成功返回的<font color = red>值</font> 
    
    - ```js
      async function main(){
          let p = new Promise((resolve,reject)=>{
              resolve('OK');
          })
          await p;
      }
      ```
  
  - Promise状态为失败
    
    - 利用`try..catch` 返回promise失败的值
    
    - ```js
      async functioon main(){
          let p = new promise((resolve,reject) =>{
              reject('Error');
          });
          try{
              let ret = await p
          }catch(e){
                  console.log(e);
              }    
      }
      ```

---

### 开发方法收录：

在CSS中，`position` 属性用于指定一个元素的定位方法。以下是 `position` 属性的常见值：

1. `static`: 默认值。元素按照文档流进行定位，不会受到其他定位属性的影响。

```css
element {
    position: static;
}
```

2. `relative`: 元素相对于其正常位置进行定位，然后通过 `top`、`right`、`bottom` 和 `left` 属性调整位置。

```css
element {
    position: relative;
    top: 10px;
    left: 20px;
}
```

3. `absolute`: 元素相对于最近的非`static`（父级或祖先）定位元素进行定位。如果没有找到非 `static` 定位的元素，则相对于 `html` 元素。

```css
element {
    position: absolute;
    top: 30px;
    left: 40px;
}
```

4. `fixed`: 元素相对于浏览器窗口进行定位，即使页面滚动，元素的位置也不会改变。

```css
element {
    position: fixed;
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%);
}
```

5. `sticky`: 元素根据用户滚动的位置进行定位。它的行为是相对定位和固定定位的混合。

```css
element {
    position: sticky;
    top: 10px;
}
```

这些是 `position` 属性的常见值。通过这些值和其他定位属性，你可以实现不同的布局效果。

---

---

## 立即执行函数

```js
for (let i = 0; i <= 5; i++) {
    arrow[i].addEventListener('click', function (index) {
        return function () {
            content[index].style.height = '150px';
            content[index].style.transition = 'height 1s ease-in-out';
        };
    }(i));
}
```

## 样式属性值在js函数的使用

#### 获取方式不要直接获取

- `window.getComputedStyle(element)`

- ```js
  let computedStyle = window.getComputedStyle(content[index]);
              // 获取带有单位的高度
              let height = computedStyle.getPropertyValue('height');
              console.log(height);
  ```

###### `content[index].style.height`

- 直接获取，可能会获取到‘未计算’的值----->空的字符串。

--- 

## 属性描述符

> 通常搭配`get`/`set` 读取器和寄存器使用----->訪問器

- 设置`属性描述符`
  
  - ```js
    Object.defineProperty(obj, propertyName, descriptor)
    //descriptor 是一个对象
    
    
    ```

-  同时设置多个属性属性描述符 `object.defineProperties` 
  
  - ```js
    Object.defineProperties(obj, {
      prop1: descriptor1,
      prop2: descriptor2
      // ...
    });
    ```

- 读取`属性描述符`信息
  
  - ```js
    let descriptor = Object.getOwnPropertyDescriptor(obj, propertyName);
    ```

#### 訪問器

```js

```



## Computing style

    声明

    层叠 ----->解决样式冲突

            优先级

                    作者样式！important

                    默认样式！important

                    作者样式

                    默认样式

            特殊性 --->四个数字（？，？，？，？）

                           1️⃣：0/1； 内联样式--->1,其余---->0

                           2️⃣：选择器中ID的数量；

                           3️⃣：类选择器、伪类选择器及属性选择器的数量；

                           4️⃣：元素选择器和伪元素选择器的数量

            原次序

                    以上均一样，后写的覆盖先写的

                    如a:hover,a:active,a:link,a:visited;

    继承

---

## 对象Obj

- `Object.keys(Obj)` keys（）方法

- 返回的是`Obj`所有的属性

- `seal()` `freeze()` 方法

---

## VUE的框架思想

- 数据响应式

- > 界面在数据更改的时候捕捉到变化并重新渲染相关模块

### VUE基础知识

- 模版语法`{{params}}`

- 计算属性
  
  - 代替了模版语法中复杂的逻辑运算
  
  - ```js
    <script setup>
    import { reactive, computed } from 'vue'
    const author = reactive({
      name: 'John Doe',
      books: [
        'Vue 2 - Advanced Guide',
        'Vue 3 - Basic Guide',
        'Vue 4 - The Mystery'
      ]
    })
    // 一个计算属性 ref
    const publishedBooksMessage = computed(() => {
      return author.books.length > 0 ? 'Yes' : 'No'
    })
    </script>
    <template>
      <p>Has published books:</p>
      <span>{{ publishedBooksMessage }}</span>
    </template>
    
    //函数/方法同理可行
    punlishedBooksMessages()
    {
        return author.books.length > 0 ? 'Yes' : 'No'
    }
    ```
  
  - **注意**
    
    - 计算属性中，此时是属性不是函数/方法；调用不需要加括号，
      
      - `{{ publishedBooksMessage }}` 
    
    - 计算属性和函数的区别
      
      - 在代码未改变的情况下，多次调用，<font color=yellow>计算属性只会渲染/计算一次</font>，而函数/方法会<font color=yellow>多次计算/渲染</font>

- 属性绑定`v-bind:`--->`:attribute` 

- 指令
  
  - `v-model``v-bind``v-on``v-if``v-show`
    
    - 组件
      
      - 组件的注册
        
        - 全局注册`app.component('MyComponent', MyComponent)`和局部注册
      
      - 组件的使用
        
        - 构建组件文件`MyComponent.vue`
        
        - 父级文件引入 Script部分`import MyComponent from './MyComponent.vue`'
        
        - 父级文件挂载组件 `export default{ component{ } }`
        
        - 父级文件  显示组件 `<MyComponent />` 
      
      - 组件`Props`传递参数（父级到子组件）
        
        - ```js
          //父级组件
          <template>
              <h3>parent</h3>
              <child title = "title"/>
          </template>
          <script>
          import child from "./child.vue"
          export default{
              data(){
          
              }
              components:{
              child
              }
          }
          ```
      
      - 组件自定义事件传递参数 （子级到父组件）`this.$emit`
      
      > 简单来说：子级设置监听事件，父级操作作为回调函数/操作

---