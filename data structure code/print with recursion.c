#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void insert(int data, int n);
void print(Node*head);

Node *head = NULL; //emppty linked list
void reverse(Node*temp);

int main()
{
    insert(2, 1); // 链表：2
    insert(4, 2); // 链表：2 4
    insert(6, 1); // 链表：6 2 4
    insert(8, 3); // 链表：6 2 8 4
    insert(10, 5); // 链表：6 2 8 4 10
    reverse(head);
    print(head);
   
   

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

void print(Node*head)
{
    if(head==NULL) return;
    printf("%d ", head->data);
    print(head->next);

    // print(head->next);// go through linked list between print()untill NULL ---> braek the inside print() and then printf
    // printf("%d ", head->data); //reverse print

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

