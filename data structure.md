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

```c
struct Node 
{
    int data;
    struct node* next; //point to node, so need to include a data-->struct
};
struct node* head; //declare a head node to represent a LL
head = NULL; //its a empty ll


struct node* temp=(strcut node*)malloc(sizeof(struct node)
// create a block memory for entering data
temp->data=2;
temp->next=NULL; //add 2 into the ll
head =temp; //let the head node point to the first element


/*add elements to the end of ll:
to the end means we need to go through the ll
so we can use (*head==NULL) to adjust if its the end of ll*/
// 添加数字到链表末尾
void append(struct Node** head, int num)
 {
    // 创建新结点
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;

    // 如果链表为空，将新结点作为头结点
    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }

    // 否则遍历至链表末尾
    struct Node* temp = *head;
    while (temp->next != NULL) 
     {
        temp = temp->next;
    }

    // 将新结点添加到链表末尾
    temp->next = newNode;
}
```
