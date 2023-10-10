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





void insertAtEnd(struct Node** head, int data) {
    // 创建一个新节点
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // 如果链表为空，将新节点设置为头节点
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // 否则，遍历链表找到最后一个节点
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // 将新节点链接到最后一个节点
    current->next = newNode;
}