#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cac(char optr,int a,int b);
int countpostfix(char*expression);
int isoperator(char A);
int isoperand(char A);
void infixtopostfix(char*expression,char*change);
int getprecedence(char op);


int main(int argc, char const *argv[])
{
while(1)
 {
	char expression[100]; //to store the expression
	char change[100];
	printf("====十以内整数计算机====\n");
	printf("輸入表達式:\n");
    fgets(expression, sizeof(expression), stdin);
    infixtopostfix(expression,change);
    int result = countpostfix(change);
    printf("結果為： %d\n", result);
 }
	return 0;
}


void infixtopostfix(char*expression,char*change)
{
	int top=-1;
	int box[100]; // to store operator as stack
	int cnt=0;

	for(int i=0;expression[i]!='\0';i++)
	{
		if(expression[i]==' '||expression[i]==',')
		{
			continue;
		}
		else if(isoperand(expression[i]))
		{
			while(isoperand(expression[i]))
			{
				change[cnt++]=expression[i++]; //output operand
			}
			change[cnt++]=' ';//to dovode the operand
			i--;
		}
		else if(isoperator(expression[i]))
			{
			  while(top>-1&&box[top]!='('&& getprecedence(expression[i]) <= getprecedence(box[top])) //adjust the precedence of operators
			  {
			  	change[cnt++]=box[top--];
			  	change[cnt++]=' ';
			  }
			  box[++top]=expression[i];//push to stack
			}
		else if(expression[i]=='(')
			{
				box[++top]=expression[i];
			}
			else if(expression[i]==')')
			{
				while(top>-1&&box[top]!='(') //have operator between parentheses 
				{
					change[cnt++]=box[top--];
					change[cnt++]=' ';
				}
				if(top>-1&&box[top]=='(')
				{
				top--;
			    }
			}
	}
		


			//after all the ( ) are done, now need to pop all...
			while(top>-1)
			{
				change[cnt++]=box[top--];
				change[cnt++]=' ';
			}
			
	change[cnt]='\0';

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
	{
		if(op2==0)
		{
			printf("錯誤，除數不能為零\n");
			exit(-1);
		}
		return (op1 / op2);
	}
	else
		{
		  printf("错误\n");
		  return -1;	
		}
}

int getprecedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

