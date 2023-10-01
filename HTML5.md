# Note for html5

> HTML     *hyper text markup language*
> 
> SO <font color=#ff0000>label</font> make up html. Every elements of html are label 

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





## Title label ----> <h1>****</h1>

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

the attribute of <font color=yellow>color width size align</font> is changeable

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

- src : source road /// <font color=yellow>the ima and the html doc must be i n the same folder</font> 

- alt: the img's name. when the img fail to display, browser will show alt name.

- title: the tips about the img when mouse float on the img will show.

    ![](/Users/jolin/Pictures/md.pic.library/img%20alt%20title.png)

- width / height : we usually change only one.

- > If we do not modify according to the image scale, it will cause stretching and distortion of the image