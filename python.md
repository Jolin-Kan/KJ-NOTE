当你已经具备C语言基础时，学习Python将会相对轻松，因为Python语法相对简洁且不需要像C一样处理底层内存管理。以下是一份快速上手Python的简要笔记，重点突出Python的一些关键特性：

### 1. Python基础

> 语句从上到下
> 
> 代码块之间<mark>通过缩进区分</mark>（相同代码块对齐）
> 
> 功能性语句（如if/while/else等）末尾加上<mark>‘：’</mark>
> 
> ‘#‘    单行注释
> 
> ‘‘’
> 
> 这里是
> 
> 多行注释
> 
> ‘‘’

`**`表示次方

`2**2`==`2^2`

#### 1.1.1 变量和数据类型

```python
# 变量赋值
x = 5

#数据转换函数
x=int(x)
x=float(x)

# 不需要显式声明数据类型
string_var = "Hello, World!"

# 常见数据类型
integer_var = 10
float_var = 3.14
boolean_var = True
list_var = [1, 2, 3]
tuple_var = (4, 5, 6)
dictionary_var = {'key': 'value'}
```

1. **整数（int）：**
   
   - 特点：表示整数，可以是正数、负数、零。
   - 字节大小：根据整数大小动态分配，无固定大小。

2. **浮点数（float）：**
   
   - 特点：表示带有小数部分的数。
   - 字节大小：通常为8字节。

3. **字符串（str）：**
   
   - 特点：表示文本序列。
   - 字节大小：字符串的字节大小取决于字符串中字符的编码和长度。对于ASCII字符，通常每个字符占用1字节，但对于Unicode字符，可能需要多个字节。

4. **列表（list）：**
   
   - 特点：有序<mark>可变</mark>序列，可以包含不同类型的元素。

5. **元组（tuple）：**
   
   - 特点：有序<mark>不可变</mark>序列，可以包含不同类型的元素。<mark>定义后不可修改</mark>

6. **集合（set）：**
   
   - 特点：无序且唯一的元素集合。<mark>元素不能重复</mark>

7. **字典（dict）：**
   
   - 特点：无序的键值对映射。
   - 字节大小：取决于字典中<mark>键值对</mark>的个数和类型。

##### 1.1.2 数据的输入输出

Input    f-string    print    函数

```python
input=input("enter the number:")
‘’‘
 int input;
 printf("enter the number:")
 scanf("%d",&input);    C.version 
‘‘’
```

- f-string--字符串格式化方法

- 允许在字符串中嵌入变量和表达式

```python
name = "Alice"
age = 25
print("姓名:", name, "年龄:", age)
print(f"姓名: {name} 年龄: {age}")
```

---



### 1.2.1運算語句

在python中可直接對數據運算

也可以<mark>對字符串”運算“</mark>

```python
print("('abc'+'123')*3")
#--->abc123abc123abc123
```



#### 1.2.2 控制流

```python
# 条件语句
if x > 0:
    print("Positive")
elif x == 0:
    print("Zero")
else:
    print("Negative")
#else if
elif x<0:
    print("Negative")

# 循环
for i in range(5):
    print(i)

while x > 0:
    print(x)
    x -= 1
```

#### 1.2.3 定義語句

> <font color=purple>將一系列運算語句結合</font>

包含函數/類    <mark>def/class</mark>



```python
# 函数定义---->'def'
def add(a, b):
    return a + b

# 函数调用
result = add(3, 4)
print(result)
```

Python中函数特点：

1. 可重复使用

2. 模块化

3. 可接收参数

> 在python的函数声明中变量的<mark>数据类型可以不声明</mark> ---只要符合函数内的运算即可
> 
> 同时也可以声明`def MAX(a:int,b:int)`<mark>-> int:</mark>
> 
> 但是python中的任何类型声明都是静态/作标记作用
> 
> <mark>不回发生强制类型转化</mark>，<font color=purple>可以输入任何数据类型，函数也能输出任何数据类型</font>



**Class** 





### 2. Python高级特性

#### 2.1 列表推导式

```python
# 列表推导式
squares = [x**2 for x in range(10)]
print(squares)
```

#### 2.2 Lambda函数

```python
# Lambda函数
square = lambda x: x**2
print(square(5))
```

#### 2.3 列表和元组拆包

```python
# 列表拆包
numbers = [1, 2, 3]
a, b, c = numbers
print(a, b, c)

# 元组拆包
coordinates = (4, 5)
x, y = coordinates
print(x, y)
```

### 3. Python面向对象编程

#### 3.1 类和对象

```python
# 类定义
class Dog:
    def __init__(self, name):
        self.name = name

    def bark(self):
        print(f"{self.name} says Woof!")

# 创建对象
dog_instance = Dog("Buddy")

# 调用方法
dog_instance.bark()
```

#### 3.2 继承

```python
# 继承
class GoldenRetriever(Dog):
    def fetch(self):
        print(f"{self.name} is fetching the ball!")

# 创建子类对象
golden = GoldenRetriever("Charlie")

# 调用父类方法
golden.bark()

# 调用子类方法
golden.fetch()
```

### 4. 异常处理

#### 4.1 try-except语句

```python
# 异常处理
try:
    result = 10 / 0
except ZeroDivisionError:
    print("Cannot divide by zero!")
```

### 5. 文件操作

#### 5.1 读写文件

```python
# 读文件
with open('file.txt', 'r') as file:
    content = file.read()
    print(content)

# 写文件
with open('output.txt', 'w') as file:
    file.write('Hello, Python!')
```

这份简要的笔记涵盖了Python的基础知识和一些高级特性。当你逐渐深入学习Python时，你还可以了解更多关于模块、包、异常处理、迭代器、生成器等更高级的主题。希望这份笔记能够帮助你快速上手Python编程。
