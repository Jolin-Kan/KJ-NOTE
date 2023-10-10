#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL; //emppty linked list

void print();
void Insert(int data);
void delete(int n);

int main()
{
int n;
head = NULL; // empty list
Insert (2);
Insert (4);
Insert (6);
Insert (5); //List : 2,4,6,5 int n;
printf("Enter a position\n");
scanf ("%d",&n) ;
delete(n);
print();
}


void Insert(int data)
{
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    Node*temp1=head;
    
    if (head == NULL) //must adjust the empty linked list--->temp1
    {
        head = temp;
    }
 else
 {
    if(temp1!=NULL)
  {
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;
  }
   else
   {
    head->next=temp;
   }
 }
}

void print()
{
    Node *temp1 = head;
    while (temp1 != NULL)
    {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
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