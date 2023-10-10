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

//     Node *temp1 = head;     // n-1 .th  node
    
//     for (int i = 1; i < n - 1 && temp1 != NULL; i++)
//     {
//         temp1 = temp1->next;
//     }
// //----------------------------------------------
//     if (temp1 == NULL) //its a empty linked list
//     {
       
//         temp->next = NULL;
//         if (head == NULL)
//         {
//             head = temp;
//         }

// //---------> to make temp as the first element

//     //-----------------------------
//         else //the linked list is not empty
//         {
//             Node *temp2 = head;
//             while (temp2->next != NULL)
//             {
//                 temp2 = temp2->next; //n-1 node
//             }
//             temp2->next = temp;
//         }
//     }
//     else
//     {
//         // 插入新节点到指定位置
//         temp->next = temp1->next;
//         temp1->next = temp;
//     }
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

