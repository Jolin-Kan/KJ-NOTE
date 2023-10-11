#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	int struct Node*next;
}node;


int main(int argc, char const *argv[])
{
	char expression[200];
	printf("请输入表达式：\n");
	gets(expression);

	int ret= count(expression);
	return 0;
}