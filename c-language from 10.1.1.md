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

-  **point** ---> to process a string
  
  - process parameters(參數)；
  
  - if the space of string is got by 'malloc'/(<font color=red>dynamic allocation of space</font>), you need to use point to handle the string.

- **array** ---> to form a string 
