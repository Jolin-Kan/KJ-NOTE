#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cac(char optr,int a,int b);
int countpostfix(char*expression);
int isoperator(char A);
int isoperand(char A);


int main(int argc, char const *argv[])
{
	char expression[100]; //to store the expression
	printf("====十以内整数计算机====\n");
	printf("輸入表達式:\n");
    fgets(expression, sizeof(expression), stdin);
    int result = countpostfix(expression);
    printf("結果為： %d\n", result);
	return 0;
}

int countpostfix(char* expression)
{
	int top = -1; //-->stack
	int box[100]; //to store operands
	int ret = 0;

	for(int i=0;expression[i]!='\0';i++)
	{
		if(expression[i]==' '||expression[i]==',')
		{
			continue; 	// skip the divide
		}
		else if(isoperator(expression[i])==1) //operator won't be stored in box[]
		{
			int op2=box[top--];
			int op1=box[top--]; //take out two operand to caculate

			ret=cac(expression[i],op1,op2); 
			box[++top]=ret; //put back the result

		}
		else if(isoperand(expression[i])==1) 
		{
			box[++top]=expression[i]-'0';//find this mistake for a long time. turn char into int
		}
	}
	return ret;
}

int isoperator(char expression)
{
	if(expression=='+'||expression=='-'||expression=='*'||expression=='/')
		return 1;
	else
		return 0;
}

int isoperand(char expression)
{
	if(expression>='0' && expression<='9')
		return 1;
	else
		return 0;
}

int cac(char optr,int op1,int op2)
{
	if(optr=='+')
		return (op1 + op2);
	if(optr=='-')
		return (op1 - op2);
	if(optr=='*')
		return (op1 * op2);
	if(optr=='/')
		return (op1 / op2);
	else
		{
		  printf("错误\n");
		  return -1;	
		}
}
