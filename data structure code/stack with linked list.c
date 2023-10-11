#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node* link;
}node;
node*top=NULL;

int main(int argc, char const *argv[])
{
	
	return 0;
}

void push(int x)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->link=top;
	top=temp;
}

void pop()
{
	if(top==NULL) return;
	node*temp=(node*)malloc(sizeof(node));
	temp=top;
	top=top->link;
	free(temp);
}