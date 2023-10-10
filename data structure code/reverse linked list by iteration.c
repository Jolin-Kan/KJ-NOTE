#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void insert(int data, int n);
void print(Node*head);
Node* reverse(Node*head);
Node *head = NULL; //emppty linked list

int main()
{
    insert(2, 1); // 链表：2
    insert(4, 2); // 链表：2 4
    insert(6, 1); // 链表：6 2 4
    insert(8, 3); // 链表：6 2 8 4
    insert(10, 5); // 链表：6 2 8 4 10
    print(head);
    head = reverse(head);
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
    Node *temp1 = head;
    while (temp1 != NULL)
    {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}

Node* reverse(Node*head)
{
    Node *current,*previous,*next;
    current=head;
    previous=NULL;
    while(current!=NULL)
     {
        next=current->next; //save the next node
        current->next=previous; //change the orientation of the linked
        previous=current;
        current=next; //manually go next node---> manually go through
     }
      head=previous;
      return head; //return the new head node after reversing
}