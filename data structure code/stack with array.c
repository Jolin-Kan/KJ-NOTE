#include <stdio.h>
#define maxsize 101 //easy to change the stack type
int top=-1;
int A[maxsize];

void push(int x);
void pop();
int Top();
int isempty();
void print();

int main(int argc, char const *argv[])
{
	push(2);
	push(5);
	Top();
	pop();
	push(7);
	Top();
	push(22);
	push(9);
	pop();
	print();
	return 0;
}

void push(int x)
{
	if(top==maxsize-1)
	{
		printf("error,the stack is full\n");
	}
	else
	{
		A[++top]=x;
	}
}

void pop()
{
	if(top == (-1))	
	printf("error,the stack is empty\n");

	top--;
	
}

int Top()
{
	return A[top];
}

int isempty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void print()
{
	if(top!=-1)
	{
		for(int n=0;n<top+1;n++)
		{
			printf("%d ", A[n]);
		}
	}
	else
	{
		printf("the stack is empty");
	}
}