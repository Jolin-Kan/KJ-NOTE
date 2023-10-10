# Data structure

<font color=red>A data structure is a way to store or organize data in a computer so that it can be used efficiently</font> 

<font color=green>we take about data structure as:</font> 

1. <font color=pink>Mathematical / logical models  /// or Abstract Data Type</font>

2. <font color=pink>Implementation</font> 

ADT: focus on the <font color=red>logic structure</font> & <font color=red>operation solution</font> 

> it doesn't include Implementation

For example: we have a Abstract view about a TV

> we know the TV can display scene and can be turned on/off
> 
> > but we don't care how the TV works by,or which manufacture produce it

So ADT is a general project / idea

> another example: 
> 
> > we need a list that can 
> > 
> > - store a given number of elements at any type
> > 
> > - Read elements by position
> > 
> > - Modify a elements by position
> > 
> > - ......
> >   
> >   we just define a model called "list"
> >   
> >   > that's ADT

when it comes to achieve it, we can use different ways with programing language to make it.

## linked list:

![](/Users/jolin/Pictures/md.pic.library/linked%20list.png)

> As we can see :
> 
> every elements of the linked list will store a data & a pointer

# linked list & dynamic array

## Advantages of linked list

1. **Dynamic RAM assign**: no need to assign memory before enter data

2. **Discontinuous storage**: elements are stored in different location in memory. No contiguous blocks of memory are required.//

3. **Easy to modify elements**

## Disadvantages of L&L

1. **Not supporting random access**: get access to one element,you have to go through all the elements before ---- O(n);

2. Require additional performance 

---

## Advantages of D-array

1. **Access to the element quickly**:  no need to go through the O(1)

## Disadvantage of D-array

1. **Fixed storage** : when you want to add a elements and the array is just full,you have to create a larger array and copy all the elements down.

2. **Complex implementation** of modifying elements:have to move major elements

---

## Make a L&L in C

> as we know every elements of the L&L have two part-->data/pointer
> 
> we can use <font color=yellow>strcture</font>

here is a way to go through the linked list

> let temp1 reach to the 'n-1'.th node

```c
 Node *temp1 = head;
        for (int i = 0; i < n-2; i++)
                {
                    temp1 = temp1->next;
                }
```

Hard to express, so linked list have a static structure

here is different example

> add to front

```c
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

void insertfront(List* plist,int x);
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
		insertfront(&list,x);
	 	
	 };
	 printList(&list);

	return 0;
}

void insertfront(List* plist,int x)
{
	node *temp=(node*)malloc(sizeof(node));
	temp->data = x;
    temp->next = plist->head; //just find the 'head'
    plist->head = temp;
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


```

> add to anywhere:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void insert(int data, int n);
void print();

Node *head = NULL; //emppty linked list

int main()
{
    insert(2, 1); // 链表：2
    insert(4, 2); // 链表：2 4
    insert(6, 1); // 链表：6 2 4
    insert(8, 3); // 链表：6 2 8 4
    insert(10, 5); // 链表：6 2 8 4 10

    print();

    return 0;
}


void insert(int data, int n)
{
    
    Node *temp = (Node *)malloc(sizeof(Node)); //temp represents a data we want to insert
    temp->data = data;

    if (n == 1) //insert to the first place
    {
        temp->next = head;
        head = temp;
        return;
    }

        Node *temp1 = head;
        for (int i = 0; i < n-2; i++)
                {
                    temp1 = temp1->next;
                }

            temp->next=temp1->next;
            temp1->next=temp;


}

void print()
{
    Node *temp1 = head;
    while (temp1 != NULL)
    {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}


```

> > eg1 avoid using global variable
> > 
> > > eg2 does not
