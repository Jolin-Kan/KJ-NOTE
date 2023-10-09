#include <stdio.h>
#include <string.h>
int main(int argc,char const *argv[])
{
	char s[]="Hello";
	char *p=s;
	printf("%s\n", s);
	printf("%s\n", p);
	printf("%d\n", *p);
    printf("%s\n", strchr(s,'l'));
	return 0;
}