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
   
   - 特点：表示整数，可以是正数、负数、零。<mark>不限制大小</mark>
   
   - > C中的整数有大小限制
     
     字节大小：根据整数大小动态分配，无固定大小。
   
   - 简单运算符
     
     - m//n ：整数除法，C中的‘/’，保留整数
     
     - m/n ： 浮点数除法，保留小数
     
     - divmod（m，n）： 输出（m//n,m%n)
   
   #### 整数的操作（类型转换）

2. **浮点数（float）：**
   
   - 特点：表示带有小数部分的数。<mark>17位小数限制</mark>
   - 字节大小：通常为8字节。
   - 浮点数进制转换出现误差
     - `4.2+2.1==6.3 Falase`
     - `4.2+2.1==6.300000000000001`
     - 所以一般判断
       - `abs((4.2+2.1)-6.3) < A
       - A是浮点数/目标精确值

3. 复数：避免歧义用`j`
   
   - 复数只能比较是否相等，不能比较大小
   
   - 提取实部和虚部
     
     - `（1+2j).real`
     
     - `(1+2j).image`

4. **列表（list）：**
   
   - 特点：有序<mark>可变</mark>序列，可以包含不同类型的元素。
   - 创建：`list =[]` / `list_name = list( )` 
     - sort（num）
     - reverse（num）
     - `num.sort(reverse=true)` ---从大到小排序
   - 以上操作都是改變原列表
   - `+` 合併.    `*n`  複製n次生成新列表
     - 類似字符串的‘運算’
   - 添加数据--    `list.append(x)` 
   - 查找
     - in  <mark>（操作符）</mark>  判斷元素是否在列表中
       - index   指定數據在列表那個位置 `index = my_list.index(3)` 
       - count   指定數據在類表中出現多少次 `count = my_list.count(2)` 
   - 計算（函数）
     - sum
     - min/max

5. **元组（tuple）：**
   
   - 特点：有序<mark>不可变</mark>序列，可以包含不同类型的元素。<mark>定义后不可修改</mark> 
   - 创建：`tuple=()` 

6. 集合 set
   
   ### 集合的创建
   
   ```python
   # 创建空集合
   empty_set = set()
   
   # 创建包含元素的集合
   fruits = {'apple', 'banana', 'orange'}
   
   # 使用 set() 构造函数创建集合
   numbers = set([1, 2, 3, 4, 5])
   ```
   
   ### 常见集合操作
   
   ```python
   # 并集
   union_set = set1 | set2  # 或者使用 set1.union(set2)
   
   # 交集
   intersection_set = set1 & set2  # 或者使用 set1.intersection(set2)
   
   # 差集
   difference_set = set1 - set2  # 或者使用 set1.difference(set2)
   
   # 对称差集 (两个集合的并集减去交集)
   symmetric_difference_set = set1 ^ set2  # 或者使用 set1.symmetric_difference(set2)
   ```
   
   ### 集合的增删改查
   
   ```python
   # 添加元素
   fruits.add('grape')
   
   # 删除元素
   fruits.remove('banana')
   
   # 检查元素是否存在
   is_present = 'apple' in fruits
   
   # 清空集合
   fruits.clear()
   ```
   
   ### 集合的其他方法
   
   ```python
   # 计算集合中元素的个数
   num_elements = len(fruits)
   
   # 复制集合
   copied_set = fruits.copy()
   
   # 判断是否为子集或超集
   is_subset = set1.issubset(set2)
   is_superset = set1.issuperset(set2)
   ```
   
   ### 集合的不可变性
   
   集合是可变的，但集合的元素必须是不可变的。例如，你不能在集合中包含列表，但可以包含元组。
   
   ```python
   # 合法的集合
   valid_set = {(1, 2), 'apple', 3.14}
   
   # 不合法的集合
   invalid_set = {[1, 2], 'banana', 2.71}
   ```
   
   8. **字典（dict）：**
   
   `Key + Value` 
   
   - 特点：无序的键值对映射。
   
   - 字节大小：取决于字典中<mark>键值对</mark>的个数和类型。
   
   - 創建:
     
     - student = { }
     
     - student = dict( )
   
   - 添加数据项
     
     - 单个直接添加`student['key']='value'` 
     
     - update法（可批量添加）： `student.update({'key2': 'value2', 'key3': 'value3'})` 
     
     - setdefault: `student.setdefault('key2', 'value2')` 
   
   - key和value用`:` 相連--->稱為一個數據項，多個數據項間`,` 間隔

#### 合併字典：

   update方法：

```python
dict1 = {'a': 1, 'b': 2}
dict2 = {'b': 3, 'c': 4}
dict1.update(dict2)
```

   print(dict1)
   {'a': 1, 'b': 3, 'c': 4} 

#### 縮減字典

- del： 刪除標籤數據項 `del dict['key']` 

- pop ： 刪除指定標籤的數據項並返回數據值 `student.pop('gender')`

- popitem ： 刪除並返回<mark>任意</mark>一個數據項 `student.popitem()`

- clear ： 清空 `dict.clear()` 

#### Access dict:

- 標籤索引： `dict[key]`

- > 如果字典內嵌套了字典----> `dict[key][0]`

- get操作 `student.get('name")`

- in操作

#### dict函數

- keys function 以列表的形式返回所有key標籤

- values function 以列表的形式返回所有value標籤

- items function 將數據項表示為二元元組`('name','tom',)` 全部返回
8. 邏輯類型：true / false
- not ---> !

- and ---> &&

- or ---> ||

# 字符串

### 1. 字符串创建：

```python
string1 = "Hello, World!" # 使用双引号 
string2 = 'Python' # 使用单引号 
string3 = """Triple quotes can 
            span multiple lines.""" # 多行字符串`
```

### 2. 字符串拼接：

```python
str1 = "Hello" str2 = "World" 
result = str1 + ", " + str2 
# 使用加号拼接字符串`
```

### 3. 字符串复制：

```python
`original = "Python" copy = original * 3 # 复制字符串三次`
```

### 4. 字符串长度：

`length = len("Python")`

### 5. 字符串索引和切片：

```python
text = "Python" first_char = text[0] # 索引
 substring = text[1:4] # 切片
```

- slice切片

- S[start : end : step]

- start from 'start',move 'step' times print;<mark> end is not included</mark>

### 6. 字符串格式化：

`name = "Alice" age = 25 formatted = f"Name: {name}, Age: {age}"`

## Python字符串高级操作：

### 1. 字符串方法：

- text = "  Python Programming  " uppercase = <mark>text.upper()</mark>    # 转换为大写

- lowercase = <mark>text.lower()</mark>   # 转换为小写 

- stripped = <mark>text.strip() </mark>             # 移除首尾空格

### 2. 字符串查找和替换：

```python
`text = "Python is easy to learn." 
index = text.find("easy") # 查找子串的位置 
replace_text = text.replace("easy", "fun") # 替换子串`
```

### 3. 字符串分割和连接及排版：

```python
csv_data = "apple,orange,banana" 
list_data = csv_data.split(",") # 分割字符串
joined_data = "-".join(["apple", "orange", "banana"]) # 连接字符串`

ljust/center/rjust：排版左中右对齐 
text.center(20)
```

---

- ##### 1.1.2 数据的输入输出

Input    f-string    print    函数

```python
n=int(input()) //类型转换
```

- f-string--字符串格式化方法

- 允许在字符串中嵌入变量和表达式

```python
name = "Alice"
age = 25
print("姓名:", name, "年龄:", age)
print(f"姓名: {name} 年龄: {age}"）   //better
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
for i in range(1,5):
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

### 函數的參數：

`def func(*args)` : 不帶key的多個參數

```python
def example_func(*args):
    for arg in args:
        print(arg)

example_func(1, 2, 3)  # 输出：1 2 3
```

`def func(**kwargs)` :以key=value的形式傳遞多個函數

```python
def example_func(**kwargs):
    for key, value in kwargs.items():
        print(f"{key}: {value}")

example_func(name="John", age=30, city="New York")
# 输出：
# name: John
# age: 30
# city: New York
```

**Class** 

### 数学函数math和Cmath

平面直角坐标和极坐标的转换

<mark>任存在浮点数计算误差</mark> 

- `cmath.polar(1+1j)`

- `cmath.rect(1,cmath.pi/2)`

### 2. Python高级特性

#### 2.1 列表推导式

用于创建列表；对于<mark>可迭代对象的元素</mark>应用表达式来快速生成列表

```python
# 列表推导式
squares = [x**2 for x in range(10)]
print(squares)
```

#### 2.2 Lambda函数

`lambda` 函数是一种匿名函数，也就是没有名称的函数。它是 Python 中的一种特殊语法，允许你创建简单的、一行的函数。`lambda` 函数通常用于需要一个小函数的地方，而不想正式定义一个完整的函数。

<mark>适合简单操作的函数</mark> 

```python
# Lambda函数
square = lambda x: x**2
print(square(5))
```

#### 2.3 列表和元组拆包

列表和元组拆包是指将一个列表或元组中的元素解包（解构）并赋值给多个变量。这使得我们可以方便地一次性取得多个值。以下是列表和元组拆包的例子：

### 列表拆包：

```python
my_list = [1, 2, 3]

# 列表拆包
a, b, c = my_list

print(a)  # 输出 1
print(b)  # 输出 2
print(c)  # 输出 3
```

### 元组拆包：

```python
my_tuple = (4, 5, 6)

# 元组拆包
x, y, z = my_tuple

print(x)  # 输出 4
print(y)  # 输出 5
print(z)  # 输出 6
```

在这两个例子中，`a, b, c` 和 `x, y, z` 分别是被赋值的变量，它们分别接收了列表和元组中的元素。需要注意的是，左边的变量数量必须与右边的列表或元组中的元素数量相匹配，否则会引发 `ValueError`。

这种拆包的方式可以在函数返回多个值时非常有用，也可以方便地交换变量的值，而不需要使用额外的中间变量。例如：

```python
# 交换变量值
a = 1
b = 2
a, b = b, a
print(a, b)  # 输出 2 1
```

这个例子中，通过 `a, b = b, a` 来实现交换，而不需要额外的中间变量。

---

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

---

## 基本拓展模块（类）





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



#### Excel文件的操作

`openpyxl`和`pandas`是两个在Python中用于处理Excel文件的流行库。它们各自有不同的用途和功能：

### `openpyxl`库：

1. **概述：** `openpyxl`是一个专门用于处理Excel文件（`.xlsx`格式）的库，它提供了灵活的API，使得可以读取、写入和修改Excel文件中的数据。

2. **基本用法：**
   
   - **读取Excel文件：**
     
     ```python
     from openpyxl import load_workbook
     
     workbook = load_workbook('example.xlsx')
     sheet = workbook.active
     cell_value = sheet['A1'].value
     ```
   
   - **写入Excel文件：**
     
     ```python
     from openpyxl import Workbook
     
     workbook = Workbook()
     sheet = workbook.active
     sheet['A1'] = 'Hello'
     workbook.save('new_workbook.xlsx')
     ```
   
   - **修改Excel文件：**
     
     ```python
     from openpyxl import load_workbook
     
     workbook = load_workbook('existing_workbook.xlsx')
     sheet = workbook.active
     sheet['A1'] = 'Modified Content'
     workbook.save('modified_workbook.xlsx')
     ```

### `pandas`库：

1. **概述：** `pandas`是一个用于数据分析的库，它提供了强大的数据结构和数据分析工具。在处理Excel文件时，`pandas`通常用于读取、写入和操作表格型数据。

2. **基本用法：**
   
   - **读取Excel文件：**
     
     ```python
     import pandas as pd
     
     df = pd.read_excel('example.xlsx')
     ```
   
   - **写入Excel文件：**
     
     ```python
     import pandas as pd
     
     data = {'Name': ['John', 'Jane', 'Bob'], 'Age': [25, 30, 22]}
     df = pd.DataFrame(data)
     df.to_excel('new_dataframe.xlsx', index=False)
     ```
   
   - **操作数据：**
     
     ```python
     import pandas as pd
     
     df = pd.read_excel('existing_dataframe.xlsx')
     df.loc[df['Name'] == 'John', 'Age'] = 26
     df.to_excel('modified_dataframe.xlsx', index=False)
     ```

### 选择使用哪个库：

- 如果你主要需要处理Excel文件（`.xlsx`格式）的底层结构，例如单元格、行和列，以及对它们进行更底层的操作，那么选择使用`openpyxl`可能更合适。

- 如果你主要处理的是表格型数据，且需要进行数据分析、处理、筛选等操作，那么选择使用`pandas`可能更为方便。

在一些情况下，这两个库可以结合使用，例如使用`openpyxl`读取底层数据结构，然后将其转换为`pandas`的DataFrame进行进一步的数据处理和分析。
