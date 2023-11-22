// 笨法一
#include <stdio.h>

typedef struct  Bst 
{
	int data;
	struct Bst* left;
	struct Bst* right;
}bst;

int isbst(bst** root);
int isbstless(bst** root,int value);
int isbstgrea(bst** root,int value);
int main(int argc, char const *argv[])
{
	
	return 0;
}

int isbst(bst** root)
{
    if (*root == NULL)
        return 1; // 空树是BST

    if (isbstless(&(*root)->left, (*root)->data) && isbstgrea(&(*root)->right, (*root)->data)
        && isbst(&(*root)->left) && isbst(&(*root)->right))
        return 1;
    else
        return 0;
}

int isbstless(bst** root, int value)
{
    if ((*root) == NULL)
        return 1; // 空子树是BST

    if (((*root)->data) <= value)
    {
        return isbstless(&((*root)->left), (*root)->data);
    }
    else
        return 0;
}

int isbstgrea(bst** root, int value)
{
    if ((*root) == NULL)
        return 1; // 空子树是BST

    if (((*root)->data) > value)
    {
        return isbstgrea(&((*root)->right), (*root)->data);
    }
    else
        return 0;
}

