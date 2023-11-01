#include <stdio.h> //create a Binary search tree about number mbers
#include <stdlib.h>


typedef struct Bst
{
	int data;
	struct Bst* left;
	struct Bst* right;

}bst;

bst* Getnewnode(int data);
void insert(bst** root,int data);
void preorderbts(bst** bitree);
 

int main(int argc, char const *argv[])
{
	bst* root=NULL; //create a empty tree
	insert(&root,15);
	insert(&root,10);
	insert(&root,20);
	insert(&root,18);
	insert(&root,30);
	insert(&root,25);

	preorderbts(&root);
	return 0;
}

bst* Getnewnode(int data)
{
	bst* newnode = (bst*)malloc(sizeof(bst));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void insert(bst** root,int data)	 //the operation to physical root ---> *root
{
	if(*root == NULL)
	{
		*root = Getnewnode(data); 
	}
	else if(data <= (*root)->data)
	{
		// bst* newnode = Getnewnode(data);
		// (*root)->left = newnode;

		insert(&((*root)->left),data); //using recursion
	}
	else if(data > (*root)->data)
	{
		// bst* newnode = Getnewnode(data);
		// (*root)->right = newnode;			you must use the recursion to update the status of the bst.
		insert(&((*root)->right),data);
	}
}

void preorderbts(bst** bitree)
{
	if((*bitree)==NULL)
	{
		return;
	}
	printf("%d   ", (*bitree)->data);
	preorderbts(&((*bitree)->left));
	preorderbts(&((*bitree)->right));
}