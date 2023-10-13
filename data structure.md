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

## Basic code structure of linked list

> We can use function to achieve 
> 
> > Insert    delete    reverse    print

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL; //emppty linked list
void reverse(Node*temp);
int main()
{
    /*code*/ it is a basic structure
             we can add different function
}


void print(Node*head) || printf linked-list with rescursion (order)
{
    if(head==NULL) return;
    printf("%d ", head->data);
    print(head->next);
}


void print(Node*head)  || printf linked-list with rescursion (reserve order)
{
    if(head==NULL) return;
     print(head->next);// go through linked list between print()untill NULL ---> braek the inside print() and then printf
     printf("%d ", head->data); //reverse print
}


void reverse(Node*temp)
{
    if(temp==NULL)
    {
        head=temp;
        return;
    }
    reverse(temp->next); //recursion to go through 
    Node *temp1=temp->next;

    temp1->next=temp;
    temp->next=NULL;
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

void insert(int data, int n) || insert front
{
node *temp=(node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = plist->head; //just find the 'head'
    plist->head = temp;

}


void delete(int n)
{
   int i;
    Node* temp1=head;
    if(n==1)
        {
            head=temp1->next;
            free(temp1);
            return;
        }
    for(i=0;i<n-2;i++)
    {
        temp1=temp1->next;
    }
    Node* temp2=temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}
```

## Doubly linked-list

every elements include one data & two pointer

```c
void insertNode(struct Node** head, int data) {
    // 創建新節點
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    // 如果鏈表為空，將新節點設為頭節點
    if (*head == NULL) 
{
        *head = newNode;
    } else {
        // 否則，將新節點添加到鏈表的末尾
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
 }
```

---

# Stack ADT    (Last-in-First-out )

> a list with the restriction that the insertion and the deletion can be performed only on one side called 'top'

## operations of stack

1. Push(x)---> to insert a x

2. pop(x)---> to remove a x

3. Top()---> to tell the data on the top of stack

4. isEmpty()---> to tell the stack is empty or not

> > <font color=red>Notice</font> : Those are done as a constant time----> O(1);

## Application:

- Function call / recursion

- Balanced parentheses // { () }

- undo in the editor----> ctrl Z

---

## Make a stack with array/linked list

> array
> 
> ```c
> 
> ```

---

# stack

> check balanced parentheses 
> 
> push '{'/'('    & check the next
> 
> if'}' / ')'    pop( )  else     push; 

# use stack to reverse a string

> 1. push the string
> 
> 2. pop the string
>    
>    > ```c
>    > typedef Node 
>    > {
>    >     char A[101]; // we are going to process string
>    >     int top;
>    > }node;
>    > 
>    > 
>    > ...
>    > 
>    > void reverse(char A[],int n)
>    > {
>    >     node*B=(node*)malloc(sizeof(node));
>    >     //loop for push
>    >     for(i=0;i<n;i++)
>    >     {
>    >      push(A[i]);
>    >     }
>    >     //loop for pop
>    >     for(i=0;i<n;i++)
>    >     {
>    >         A[i]=Top();
>    >         pop();
>    >     }
>    > 
>    > }
>    > ```

## Use stack to reverse a linked-list

> 1. we need a temp node
> 
> 2. the operations in a loop
> 
> 3. temp node to go through as head
>    
>    > temp=top;
>    > 
>    > head=temp    //reverse head node
>    > 
>    > pop();    //top has been reversed and we need another element to be                 reversed as top()
> 
> 4. change the connection
> 
> > <font color=yellow>get in loop</font>
> > 
> > temp->next=top()    // (now)top is already reversed by temp
> > 
> > pop()     // switch to next to reverse
> > 
> > temp=temp->next // move temp to next

## postfix    infix    prefix

> different way of representing 'expression'
> 
> | infix   | postfix | prefix |
> | ------- | ------- | ------ |
> | a+(b*c) | abc*+   | +*abc  |

# Use stack to count <font color=yellow>postfix</font>

1. one list for operand and one stack for operator

2. if is operand add to list

3. if is operator,pop two previous operands and calculate; then push the ret in list

# use stack to transform infix to postfix

1. create a stack to store operator / parentheses 

2. output the operand 

3. if the stack is not empty && no higher precedent operator --> push

4. if the stack is not empty && do have a higher precedent operator pop() all the operators then push
   
   <font color=red>5. </font> about parentheses if '(' match ')', all the operators between parentheses <font color=red>pop</font>



---

# Queue



The queue is a common linear data structure, which operates based on the first-in-first-out <font color=yellow>(FIFO)</font> principle, which means that the elements that**** first enter the queue will be deleted first.**** The queue is usually used to simulate queuing, such as operating system task tuning, packet transmission, etc. in computer science.

### Achieve queue in C
