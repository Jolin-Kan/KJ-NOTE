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
