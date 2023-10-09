#include <stdio.h>
#include <stdlib.h>


typedef struct _node
{
	int data;
	struct _node *next;
}node;

typedef struct _List
{
	node *head;
  //node *tail;
}List;   // we use a brand new data type to represent the whole Linked-list 

void insert(List* plist,int x);
void printList(List* plist);


int main(int argc, char const *argv[])
{
	
	 List list;
	 list.head=NULL;
   //List.tail=NULL;

	 int i,n,num,x;										 //
	 printf("How many numbers do you want to enter?\n"); //
	 scanf("%d", &n);									 //
	 
	 for(i=0;i<n;i++)
	 {
	 	printf("What's the number?\n");
		scanf("%d", &x);
		if(i==(n-1))
			{
				printf("\n");
			}
		insert(&list,x);
		printf("The list is:\n");
		
	 	
	 };
	 printList(&list);

	return 0;
}

void insert(List* plist,int x)
{
	node *temp=(node*)malloc(sizeof(node));	//assign the memory!!!
	temp->data=x;
	temp->next=NULL;

	//go through the ll, move on to netx element

	node *last=plist->head;  //let last to go through the ll instead of head,because head should'n be modified

	//to find the last element
	if(last!=NULL) //if the linked-list is not empty
	{
	while(last->next!=NULL)
		{
			last=last->next;

		}
		last->next=temp; 
	}
	else
		{
			plist->head=temp;
		}


}

void printList(List* plist)
{
    node *temp = plist->head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

