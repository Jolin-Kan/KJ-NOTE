## Ajax -- 异步js和xml

### 优点：

- 无需刷新 更新内容

- 根据用户事件 刷新 部分内容

### 缺点：

- 无浏览历史，不可回退

- 存在跨域问题 【跨网站】 

- SEO不友好 

## HTTP协议及express框架使用

#### HTTP协议

- #### 请求报文

```
行      POST  /s?ie=utf-8  HTTP/1.1 
头      Host: atguigu.com
        Cookie: name=guigu
        Content-type: application/x-www-form-urlencoded
        User-Agent: chrome 83
空行
体      username=admin&password=admin
```

- #### 响应报文

```
行      HTTP/1.1（版本号）  200（状态码）  OK（状态字符串）

                          xhr.status   xhr.statusText

头      Content-Type: text/html;charset=utf-8
        Content-length: 2048
        Content-encoding: gzip

        `xhr.getAllResponseHeaders()` 
空行    
体      <html>
            <head>
            </head>
            <body>
                <h1>尚硅谷</h1>
            </body>
        </html>

        `xhr.response`
```

HTTP状态码：404、401、410、200、500.....

XHR.status

`注：2XX均是接通成功` 

```js
if(xhr.status >= 200 && xhr.status < 300){
    //......
}
```

### 操作Ajax请求的基本步骤

> 使用XMLHttpRequest
> 
> <color = blue>在监听函数内完成一下操作</color> 

1. `new XMLHttpRequest( )`定义xhr对象

2. `XMLHttpRequest.open(方法字符串,URL,...,...)` 设置请求方式/URL 和服务器连接 

> 利用URL传参 ： `Http://127.0.0.1:8000/serve?name=value&name2=value2` 

    3.`XMLHttpRequest.onreadystatechange()`注册事件

    4.`XMLHttpRequest.send()` 发送请求

### 设置报文:

#### 行：

- 利用`XMLHttpRequest.open(方法字符串,URL,...,...)`

#### 头：

- `XMLHttpRequest.setRequestHeader('Content-Type','application/x-www-form-ulencoded)` 

#### 响应体（参数）：

- `xhr.send(a:100&b=200)`

- 集成在`XMLHttpRequest.open(方法字符串,URL,...,...)` 的URL中
  
  - `http://127.0.0.1:8000/serve?a=100&b=200` 

---

## IE缓存问题

> IE浏览器 会对服务器response作缓存，在此发送请求时会走本地路线，若response变化则不能及时更新，缺乏时效性

- 解决方法：在URL中添加时间戳---让服务器认为这是不同的URL，就不会走本地路线

- `xhr.open('GET','http://127.0.0.1:8000/ie?t='Date.now());` 

---

## 手动取消请求

- abort（）方法 ----> XMLHttpRequest

- `x = new XMLHttpRequest(); x.abort();`  

---

# jQuery 使用Ajax

- Ajax方法

> ```
> $("button").click(function(){
>     $.ajax({url:"test.txt",data:{a:100},type:'GET',
>     success:function(result){
>         $("#div1").html(result);//一般是输出
>     dataType:"Json"
>     }});
> }); 
> //参数是对象，包含URL/请求类型/参数/响应体的结果/成功后的回调callback
> ```

- - | async                        | 布尔值，表示请求是否异步处理。默认是 true。                                   |
    | ---------------------------- | ---------------------------------------------------------- |
    | beforeSend(*xhr*)            | 发送请求前运行的函数。                                                |
    | cache                        | 布尔值，表示浏览器是否缓存被请求页面。默认是 true。                               |
    | complete(*xhr,status*)       | 请求完成时运行的函数（在请求成功或失败之后均调用，即在 success 和 error 函数之后）。<br>     |
    | contentType                  | 发送数据到服务器时所使用的内容类型。默认是："application/x-www-form-urlencoded"。 |
    | context                      | 为所有 AJAX 相关的回调函数规定 "this" 值。                               |
    | data                         | 规定要发送到服务器的数据。                                              |
    | dataFilter(*data*,*type*)    | 用于处理 XMLHttpRequest 原始响应数据的函数。                             |
    | dataType                     | 预期的服务器响应的数据类型。                                             |
    | error(*xhr,status,error*)    | 如果请求失败要运行的函数。                                              |
    | global                       | 布尔值，规定是否为请求触发全局 AJAX 事件处理程序。默认是 true。<br>                  |
    | ifModified                   | 布尔值，规定是否仅在最后一次请求以来响应发生改变时才请求成功。默认是 false。                  |
    | jsonp                        | 在一个 jsonp 中重写回调函数的字符串。                                     |
    | jsonpCallback                | 在一个 jsonp 中规定回调函数的名称。                                      |
    | password                     | 规定在 HTTP 访问认证请求中使用的密码。                                     |
    | processData                  | 布尔值，规定通过请求发送的数据是否转换为查询字符串。默认是 true。                        |
    | scriptCharset                | 规定请求的字符集。                                                  |
    | success(*result,status,xhr*) | 当请求成功时运行的函数。                                               |
    | timeout                      | 设置本地的请求超时时间（以毫秒计）。                                         |
    | traditional                  | 布尔值，规定是否使用参数序列化的传统样式。                                      |
    | type                         | 规定请求的类型（GET 或 POST）。                                       |
    | url                          | 规定发送请求的 URL。默认是当前页面。<br>                                   |
    | username                     | 规定在 HTTP 访问认证请求中使用的用户名。                                    |
    | xhr                          | 用于创建 XMLHttpRequest 对象的函数。                                 |

- 

---

#### 利用express框架

##### 基本使用步骤

1. **引入 Express 模块**：
   
   ```javascript
   const express = require('express');
   ```
   
   这一步用于导入 Express 模块，使其在脚本中可用。

2. **创建应用对象**：
   
   ```javascript
   const app = express();
   ```
   
   通过调用 `express()` 函数，创建了 Express 应用对象。该对象用于配置和管理整个 Express 应用。

3. **创建路由规则**：
   
   ```javascript
   app.get('/', (request, response) => {
       response.send('HELLO EXPRESS');
   });
   ```
   
   使用 `app.get()` 定义路由规则。在这个例子中，当收到 GET 请求并且路径是根路径 `'/'` 时，执行回调函数并发送 "HELLO EXPRESS" 作为响应。

4. **监听端口并启动服务**：
   
   ```javascript
   app.listen(8000, () => {
       console.log("服务已经启动, 8000 端口监听中....");
   });
   ```
   
   使用 `app.listen()` 指定服务器要监听的端口号（这里是 8000）。一旦调用了 `listen`，服务器开始监听指定的端口，并在启动时执行回调函数。

这是 Express 框架的入门步骤

`^c`关闭服务端口

---
