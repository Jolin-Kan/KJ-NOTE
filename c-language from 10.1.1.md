# Note for C language with markdown(from     10.1.1-string)

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

> Notice: scanf () only scan a 'word' <font color=green>(divided by empty, tab or enter)</font> once.

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

it means we have a pointer called string and this pointer(string) point to another pointer.That pointer point to a character. 

look at 1&3: 

#### No.2

its similar to a <u>***two-dimensional array***</u> 

it means there is a array and each elements of the array have the capacity of 10 character.

#### No.3/4

 a is a array and its elements are pointers that point to character 

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

- Everything needs parentheses
  
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
  
  > 不要忘記<font color=yellow>逃逸字符</font> 如'\n' return
