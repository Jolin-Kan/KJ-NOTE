# Note for html5

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

- 有別與之前所提及的段落<p>標籤

> 段落標籤承載的是一段話，而文本標籤單純承載<mark>词汇</mark>

### 文本标签的类型：

```html
    <em></em>     emphasis
    <b></b>    bold
    <i></i>    italic
    <strong></strong> like bold
    <del></del>    delete line
    <span></span>    meaningless
    <p>my favouoite camara brand is <b>Nikon</b></p>
```

![](/Users/jolin/Pictures/md.pic.library/文本标签效果.png)

- 如圖，文本標籤還可以嵌套在<p>中使用

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

![](/Users/jolin/Pictures/md.pic.library/列表效果.png)

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