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

### Point or array ? (code 1.or 2.?)

- **point** ---> to process a string
  
  - process parameters(參數)；
  
  - if the space of string is got by 'malloc'/(<font color=red>dynamic allocation of space</font>), you need to use point to handle the string.

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



### $ getchar$ & $putchar$ -----> string function with $<string.h>$

1. <font color=pink>**the difference between $getchar$ & $printf$ ; $putchar$ & $scanf$**</font>

> $scanf$ and $printf$ can process more than one string/data at the same time
> 
> > But putchar and getchar works character by character 

2. The unique superiority of putchar & getchar

## **they can read and display string with space!**

because space is regarded as a character.

---

---

## How to represent a string array

```c
1. char **string;
2. char [][10];
```

here is two way of representing a string array:

#### No.1

it means we have a point called string and this point(string) point to another point.That point point to a character/string.

#### No.2

its similar to a <u>***two-dimensional array***</u> 

it means there is a array and each elements of the array have the capacity of 10 character.
