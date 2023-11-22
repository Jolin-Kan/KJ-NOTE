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