# C programing language 匯總版（待校验)

```markdown
# C语言笔记

## 基本程序模型

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

C语言的基本程序模型以分号结束每一句。

- `#include <stdio.h>` 包含头文件。
- `int main()` 主函数的入口。
- `printf("Hello, World!\n");` 打印文本。
- `return 0;` 返回整数值0。

`printf("XXX");` 用于显示文本。

`int` 用于定义整数，`int A = B` 表示定义一个名为A的变量，其初始值为B。

`const int A = B` 表示A是一个常量，其值为B。

`scanf("%d", &input)` 用于从控制台读取整数。

- `%d` 表示整数。
- `%f` 表示浮点数。

使用 `int` 时，要使用 `scanf("%d")`。

使用 `double` 时，要使用 `scanf("%lf")` 和 `printf("%f")`。

## 算子和运算符

- `&` 是一个运算符，用于取变量的地址。
- `sizeof()` 是一个运算符，用于计算括号内数据类型的内存占用空间。

自增（`++`）和自减（`--`）运算符，可以放在前或后。

- `a++` 等同于 `a = a + 1`。
- `++a` 等同于 `a = a + 1`。

BCD（二进制编码十进制）是将十进制数转化为十六进制数，去掉`0x`前缀。

## 控制结构

### If语句

```c
if (条件) {
    // 执行条件为真时的代码
} else {
    // 执行条件为假时的代码
}
```

`if` 可以改成 `while` 并在执行条件后加上分号，这样就变成了 `while` 循环。`while(0)` 不执行循环，`while(1)` 永远执行循环。

### Do-While循环

```c
do {
    // 循环体
} while (条件);
```

`do-while` 先执行循环体，然后检查条件。而 `while` 先检查条件，再执行循环体。

### Switch-Case语句

```c
switch (expression) {
    case constant1:
        // 代码块1
        break;
    case constant2:
        // 代码块2
        break;
    default:
        // 默认代码块
        break;
}
```

`switch-case` 可以代替级联的 `if-else` 语句。

### For循环

```c
for (初始化语句; 循环继续的条件; 循环要执行的语句) {
    // 循环体
}
```

## 函数

函数由返回类型、函数名、参数列表和函数体组成。

函数调用使用函数名，并提供相应的参数。

函数可以有返回值，也可以是 `void` 表示没有返回值。

函数的参数可以是值传递，也可以是指针传递。

```c
返回类型 函数名(参数列表);    //function's statement

返回类型 函数名(参数列表) {
    // 函数体
}
```

`the name of function can be passed between different scopes(作用域）`

`so function is actually a kind of pointer`

> BTW,computer need to assign memory for the <font color=red>body of function</font>

### Function pointer (variable)

```c
int Func(int x);   /*声明一个函数*/
int (*p) (int x);  /*定义一个函数指针*/
p = Func;          /*将Func函数的首地址赋给指针变量p*/
```

> I need to further studying to figure out why its significant.
> 
> 函数指针可以理解为给函数创建了一个别名，使得在函数的作用域利用 别名调用函数
> 
> 但函数指针精妙之处在于可以在程序运行的时候改变函数指针指向的函数从而改变执行的函数

---

## 数据类型

> <mark>实型常量又称实数或浮点数</mark>

C语言支持不同数据类型：

- 整数类型：`char`, `short`, `int`, `long`, `long long`
- 浮点数类型：`float`, `double`, `long double`
- 逻辑类型：`bool`
- 指针类型
- 用户自定义类型

#### Integer

数据类型有不同的范围和精度。整数类型会有最大和最小值的限制。

### float

  注：%e指使用科学计数法

e.g 1230000 == 1.23E+16

浮点数的输出可在%和f之间添加精度(遵循四舍五入）

Printf(“%.30f”,0.049）—> 0.05

浮點數在計算機內部的表達：

個人理解：將浮點數轉化爲二進制的科學計數法，double佔據八字節，64bit，將這些位分為三部分，“符號位，階碼，尾數”分別表示 正負、二進制的指數、科學計數法的小數部分（尾數）

<mark>/float數值的表達要在最後加f，—> 1.23f；如果沒加，儘管定義為float，都當作double</mark>

## 数组

数组是一组相同数据类型的元素。

```c
int array[5];
```

数组的元素可以通过索引访问，索引从0开始。

```c
array[2] = 10;
```

数组的大小可以使用 `sizeof` 操作符来确定。

## 指针

指针是用来存储变量地址的变量。

```c
int *p = &a;
```

指针变量可以用于传递变量的地址，从而在不同函数之间传递数据。

## 动态内存分配

使用 `malloc` 函数来分配动态内存。

```c
int *array = (int *)malloc(5 * sizeof(int));
```

分配后，需要使用 `free` 函数释放内存，否则会导致内存泄漏。

## 字符串

字符串是字符的数组。

```c
char str[] = "Hello, World!";
```

C语言中没有内置的字符串类型，字符串通常使用`字符数组`表示。

## String & Character array

```c
char word['h','e','l','l','o','!'];

char word2['h','e','l','l','o','!','\0'];
```

<font color=yellow>word</font> is a string array

<font color=green>word2</font> is a string 

// <font color=red>in C ,a string array end with '\0',0    is a string.

## string (essentially still a array)

- definition: a string of character end with 0 / '\0'

> 0 is equal to '\0' ; but '0' means a character 0

> 0 / '\0' represents the end of the string,but its not the part of the string
> 
> however the zero still occupy a byte.

```c
char word3 [10]={hello};
char word4[10]={hello world};
```

word4 actually has a total of 11 elements > array's effective range ---<font color=red>X</font>

We have to remember that there is a 0 in the end of the string

<font color=yellow>**So the number of string's character <= (array max) -1**</font>

- string exits as array, access as point or array (always as the point)

<string.h> string function

### string variable has different expression form

```c
1. char *str="Hello";
2. char word[]="Hello";
3. char line[10]="Hello";
```

1. we have a point called str which points to a string(Hello)'s address

2. we have a string array which is <font color=red>initialized</font>[^1] to "Hello".

3. we have a string array with the size of 10 bytes and we put a "Hello" in it.

[^1]: its unique to C language

## further research about code 1.& 2.

### string variable & string constant

```c
char *str="Hello";
```

str is a point which is initialized to point to a ***string constant***  --->  Hello

> <font color=green>char *str == const char *str</font>
> 
> > str is actually read only  //string constant

If we need to rewrite the string we have to use string array

> char word[]="Hello";

### Pointer or array ? (code 1.or 2.?)

- **pointer** ---> to process a string
  
  - process parameters(參數)；
  
  - if the space of string is got by 'malloc'/(<font color=red>dynamic allocation of space</font>), you need to use pointer to handle the string.

- **array** ---> to form a string 

## string's print & scan

> I will use some example to illustrate some ways of printing/scanning string

---

### 1.字符串間不能作賦值

```c
char *t = "title";
char *s;
s = t ;
```

It doesn't create a new string and actually t and s point to the same address

### 2. scan and print

```c
char string[8];
char word[8];
scanf("%s", string); //scanf("%7s", tring);
scanf("%s", word); //scanf("%7s", word);
printf("%s\n", string);
printf("%s\n", string);
```

> <font color=blue>Notice: scanf () only scan a 'word' (divided by empty, tab or enter)</font> once.</font> 

So scanf() will scan the word one by one(if needed) ----

If it needs to scan only one string and we enter more than one, the rest of the string will be ignore. And sometimes <font color=green>if the size of the word is bigger than the string array requires, it will fail to scan. </font>

So <font color=red>"%7s"</font> is used to limit the size of string the program scan. If we enter a string bigger than the size required, the program will scan as much as it can and the rest will be scanned to the next string array or just being ignored.

### $ getchar$ (void)& $putchar$ (int) -----> string function with $<string.h>$

1. <font color=pink>**the difference between $getchar$ & $printf$ ; $putchar$ & $scanf$**</font>

> $scanf$ and $printf$ can process more than one character/data at the same time
> 
> > But putchar and getchar works character by character 

2. The unique superiority of putchar & getchar

## **they can read and display string with space!**

because space is regarded as a character.

--- ---

## How to represent a <font color=yellow>string array</font> = string's pointer array

> > it means <font color=pink>there is a array whose elements are pointer and those pointers point to a character so that it forms a string array</font> 

> string actually is a <string array> 

```c
1. char* *string;
2. char a[][10];
3. char* a[]; 
4. char* string[10];
```

here is two way of representing a string array:

#### No.1

1. char* ----> pointer point to character

2. char** ----> a pointer point to another pointer == form an array

it means we have a pointer called string and this pointer(string)  to another pointer.That pointer point to a character. 

look at 1&3: 

#### No.2

its similar to a <u>***two-dimensional array***</u> 

it means there is a array and each elements of the array have the capacity of 10 character.

#### No.3/4

 a is a array and its elements are pointers that point to character 

---

> ```c
> int s[4][5],(*ps)[5]; /* , represent s&ps share the 'int'*/
> int *p[5]
> 
> ps+1; ---->point to the next row of the 2D array(s),exactly the 
>             second row of the S
> 
> *(ps+3);--->(ps+3)==pointer to the fourth row of the S
>             -----> *(ps+3)==that array,the fourth row of S.  
> 
> *(ps+1)+3;---->*[(ps+1)+3]
> (ps+1)+3----> the fourth element of the second row of the S
>               (s的第二行数组的第四个元素)
> *(ps+1)+3 ----> that element's *address* 
> 
> 
> char a[5][5] & int a[5][5]
> ！！！！！！     string array & 2D array   !!!!!!!!!
> ```

ITs a quite interesting epression:

so <font color=yellow>ps</font> represents a pointer to an <font color=pink>array with the size of 5 integers</font>--->and this array is exactly <font color=green>S 's first row</font>

> <font color=HOtpink>the parentheses is necessary!!!</font>

#### However

#### <font color=hotpink>P</font> represents an array of pointer (指针数组)

> there is an array of five pointers. The element of the array, pointer, to an integer.

---

# <font color=red>Notice:</font>  'int main()' actually has something in parentheses

```c
int main(int argc,char const *argv[])
```

> argc means the number of the parameters .
> 
> argv[] is a pointer array which point to every parameter in the main function.

---

## function in the <string.h>

> because string can be represented by two ways
> 
> > so the function can also be written by two ways

1. ### **strlen** (const char *s)-----> to know the length of string

> > ```c
> > //count,no need to rewrite ---> CONST
> > strlen(string);
> > sizeof(string);
> > ```

<font color=pink>"sizeof" has no business with the length of string</font>

> write our own strlen function:
> 
> ```c
> int cnt=0;
> int idx=0;
> while(s[idx] != '\0')
> {
>     idx++;
> }
> return idx;
> ```

2. ### strcmp(const char *s1, const char *s2) // compare, no need to rewrite

>  compare the string's size
> 
> the result is subtraction of the two string's address

```c
strcmp(s1,s2);


while(s1[idx]==s2[idx]&&s1[idx] != '\0')
{
    idx++;
}
return s1[idx]-s2[idx];


while(*s1==*s2&& *s1!='\0')
{
    s1++;
    s2++;
}
return *s1-*s2;
```

3. ### char* strcpy(char* restrict dst, const char* restrict src)
   
   > > <font color=yellow>copy src to dst</font>

```c
while(src[idx] != '\0')
{
    dst[idx]=src[idx]
    idx++
}
dst[idx]= '\0'
return dst;
```

> how we use it?
> 
> when we copy a string, we have to create a empty space that can contains the string we need to copy -----> <font color=pink>malloc</font> /old friend/
> 
> ```c
> char *dst = (char*)malloc(strlen(src)+1);
> strcpy(dst,src);
> ```

4. ### char* strchr(const char*s, int c); // search from left

### char* strrchr(const char*s, int c); //search from right

> search a character in a string // strchr() will tell us the address of the first character we ask to search.
> 
> ```c
> char s[]="Hello";
> char *p= strchr(s,'l');
> p=strcgr(p+1,'l');//search the other 'l' during s
> 
> char c = *р;
> *р = "10';
> char *t = (char*) malloc(strlen (s)+1);
> strcpy(t, s);
> printf("&s\gh
> t)
> free(t); //print the spring before 'l'
> ```

5. ### strcat()----> connect/combine two strings

```c
#include <stdio.h>
#include <string.h>
int main(){
    char str1[101] = { 0 };
    char str2[50] = { 0 };
    gets(str1);
    gets(str2);
    strcat(str1, str2);
    puts(str1);

    return 0;
}
```

---

---

> > # gets(int) // scanf() // getchar()

> ```c
> char *fgets(char *str, int num, FILE *stream);
> ```
> 
> > stdin    stdout   stderr ---> *stream
> > 
> > > 用於輸入的時候
> > > 
> > > stdin 指從鍵盤輸入    stdout/stderr  默認為顯示器

---

> **gets**(char *str); -----> unlimited 
> 
> > **fgets**() and **gets**() return a pointer to the string
> > 
> > > <font color=yellow>lacks of bounds checking, and the inability for the calling program to reliably determine the length of the next incoming line,</font>
> > 
> > use fgets() instead of gets() in any case.

### putchar(c) has three types of output

1. 当c为一个被单引号（英文状态下）引起来的字符时，输出该字符（注：该字符也可为[转义字符](https://link.zhihu.com/?target=https%3A//baike.baidu.com/item/%25E8%25BD%25AC%25E4%25B9%2589%25E5%25AD%2597%25E7%25AC%25A6)）；

2. 当c为一个介于0~127（包括0及127）之间的十进制整型数时，（**此时没有单引号引起来**）它会被视为对应字符的[ASCII](https://link.zhihu.com/?target=https%3A//baike.baidu.com/item/ASCII)代码，输出该ASCII代码对应的字符

3. 当c为一个事先用char定义好的字符型变量时，（**此时没有单引号引起来**），输出该变量所指向的字符。
   
   > ```c
   > int ch;
   >     while((ch=getchar())!= EOF)
   >     {
   >         putchar(ch);
   >     }
   > return 0;
   > ```
   > 
   >  in this code, ch is a defined string variable\
   > 
   > so putchar can output more than one character
   
   ---
   
   ---
   
   ---

## Enumeration

>  help to define some names that can be piled up and ordered.
> 
> like monday -- sunday......

Basic structure //int type

```c
enum COLOR {red,yellow,green=5} //just like array,we can handly initialized
```

### Tips:

enum starts from 0, at the end of the enumeration we usually add a "colorofXXX" to reveal how many element are there. Num = enum colorofXXX

---

# **struct**

there is three forms to declare a struct

> <font color=pink>name is no necessary</font> 

```c
struct date{
    int year;
    int month;
    int day;
};
struct date today,tomorrow;


struct {
    int year;
    int month;
    int day;
}today,tomorrow; // only define two variable rather than a struct
```

### struct member

<font color=yellow>we also have different ways to initialized the struct member</font> 

```c
struct date{
    int year;
    int month;
    int day;
};
struct date today={2023,10,3};
struct date tomorrow={2023,10,4};
struct date aday={.year=2023,.day=23};

struct date oneday;
oneday.year=2023;
oneday.month=11;
oneday.day=22;
```

1. initialize like array does
   
   > initialize in order. If not initialized, it defaults to 0;

2. initialize it one by one;

> '.' "運算符"
> 
> connects struct and struct member

### struct caculate

```c
struct 
{
    int x;
    int y;
}p1,p2;

p1=(struct){10,5}; ------> p1.x=10; p1.y=5
p1=p2; -----> p1.x=p2.x;  p1.y=p2.y
```

### struct and function

> we can <font color=yellow>assign values</font> from struct to struct
> 
> > arguments are passed between function <font color=yellow>as Values</font> 

E.g.1:

![](/Users/jolin/Pictures/md.pic.library/struct&function1.png)

Structs are assigned inside a function and cannot <font color=green>be taken out to the other function</font> for output <font color=red>[[  because Arguments are passed as values  ]]</font> 

solution for passing struct:

1. copy the whole struct

2. use a pointer

Obviously use a pointer is more <font color=pink>efficient.</font> 

#### For example:

![](/Users/jolin/Pictures/md.pic.library/struct&function2.png)

focus on the function "getstruct" it return a address which point to a struct by which way we can extract the struct from the pointer in any function.

> that means we can pass the struct between functions without modifying its value.

### <font color=red>-></font> similar to '<font color=red>**.**</font>'

> to represent the member of the struct that a pointer pointy to
> 
> ```c
> struct date
> {
>     int year;
>     int month;
> }myday;
> struct date *p = &mydate;
> p->month=12;//1
> (*p).month=12;//2
> ```
> 
> 1 & 2 has the same meaning

### struct in struct

```c
struct point
{
    x;
    y;
};

struct rpoint
{
    struct point pt1;
    struct point pt2;
};

struct rpoint r,*rp;
r.pt1.x    /    r.pt1.y
r.pt2.x    /    r.pt2.y


rp=&r;
r.pt1.x == rp->pt1.x
//no  rp->pt1->x
pt1 is not a pointer
```

---

---

---

## Typedef + <original type> + <new name>

> > Find <font color=red>the last word</font>  to distinguish!!!!

Typedef int length;

> // we can use 'length' to define int variable

Typedef char* string[10];

> // string represent a string array that has 10 elements
> 
> string a; // means a is a string array that has 10 elements

Typedef struct node anode;

> struct node a == anode a;

---

## 1. Global variable & Static Global variable

## 2. Local variable & Static Local variable

Global & Local

> **the variable defined in a function is called 'Local variable'**
> 
> when getting out the function the variable will disappear(the address will be assigned for other variables)
> 
> > **the variable defined out of the function is called global variable**
> > 
> > the variable will only be initialized once

### Static

> Static means a variable will exist forever.
> 
> if we have a static local variable 
> 
> ```c
> static int i;
> ```
> 
> 'i' 's address will be kept forever even if the function i below is done.

---

## Macro-define(宏定義)/ #define

> kind of <font color=red>**Compile preprocessor instruction**</font> /(編譯預處理指令)
> 
> is not the part of the C language
> 
> >  its actually to replace something

# #define A B

> when running the code, the <font color=yellow>compiler</font> will find <font color=red>all</font> the A in code and replace with B

Example:

```c
#include <stdio.h>
#define PI 3.14159


int main()
{
    printf("%f", PI*4)
/* the result of the program is 
    3.14159*4*/
}
```

## <font color=pink>Macro-define with parameter</font>

> actually we can assign parameter in Macro-define
> 
> > Basically its just like function,we can <font color=green>write a function</font> with Macro-define
> > 
> > Western programmer will do so but eastern programmer do not.

```c
//Here is some wrong example:
1.#define A(x) (x*300)
2.#define A(x) (x)*300

printf("%d", A(5+2));==> 5+2*300
printf("%d",10/A(7));==> 10/7*300
```

### Some principles of Macro-define with parameters

- Every single thing needs parentheses
  
  - the parameter needs parentheses 
  
  - the value needs parentheses

- we can have more than one parameters

- we can also have nested Macro-define

- do not add ';' in the end of the Macro-define

- ### '/'    '//'    '#'    '##'

```c
1. #define AAA printf("Hello") /
2.            printf("world")
3. //'/' means the Macro-define didn't end. Line 1&2 is in one Macro-define

4.#define AAAA printf("fuck")
5.             printf("up")
6. //without a '/' is not available. the code in line5 is regarded as empty instruction
```

'#'    turn parameter below into character ----> to print

'##' to connect front and backyard parameters  

## Final step

> it includes some <font color=yellow>advance and primitive</font> thing in computer and C
> 
> And those are not so urgent for me to understand or use it
> 
> > so I will briefly choose something I can understand well and I think is necessary to mark down

### 源代碼文件  /  head file(頭文件)

> In some case, we define or use lots of functions and make the code too redundant(冗雜的) so that its not good for modifying the code & reading
> 
> > **and we know the "<stdio.h>" is one of the <font color=red>stander repository</font> of C **
> > 
> > **the repository includes abundant functions**
> 
> So we can write our own repository and store them with the original code
> 
> that's called <font color=yellow>project</font>
> 
>  // the specific implementation is not included in this note

### The format of ***print*** and ***scan***

printf ----> "%[flags] {[width]/[.prec]} [hlL]type"

![](/Users/jolin/Pictures/md.pic.library/flag...png)

> > No '-'    default align to right
> > 
> > (+-%d) /(-+%d) means need a sign and align to left at the same time 

![](/Users/jolin/Pictures/md.pic.library/pre.png)

> > ("%9.2f")  means the float totally takes up 9 characters and there is two characters after the '.'
> > 
> > "_ _ _ _ _99.23"

![](/Users/jolin/Pictures/md.pic.library/print%20type.png)

> I mentioned before so just review it.

Scanf ---> %[flag]type

![](/Users/jolin/Pictures/md.pic.library/scan%20type.png)

> learn it by heart

## printf & scanf actually return something!!!

- the number of items it reads

- the number of character it print
  
  > 不要忘記<font color=purple>逃逸字符</font> 如'\n' return

---

# C语言中的按位运算和移位运算

## 按位运算运算符

- `&`（与）：对应位都为1时，结果位为1，否则为0。
- `|`（或）：对应位有一个为1时，结果位为1，否则为0。
- `^`（异或）：对应位不同，结果位为1，相同则为0。
- `~`（取反）：对操作数的每一位取反，1变为0，0变为1。

## 移位运算运算符

- `<<`（左移）：将操作数的二进制位向左移动指定的位数，右侧用0填充。
- `>>`（右移）：将操作数的二进制位向右移动指定的位数，左侧用符号位（带符号整数）或0（无符号整数）填充。

### 按位运算示例

```c
int a = 5;  // 二进制：00000101
int b = 3;  // 二进制：00000011

int and_result = a & b;  // 00000001 (1)
int or_result = a | b;   // 00000111 (7)
int xor_result = a ^ b;  // 00000110 (6)
int not_result = ~a;     // 11111010 (-6)
```

### 移位运算示例

```c
int num = 12;  // 二进制：00001100

int left_shift_result = num << 2;  // 00110000 (48)
int right_shift_result = num >> 2; // 00000011 (3)
```
