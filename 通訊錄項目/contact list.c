#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h> //enter phone number & character info

typedef struct Contact 
{
    char name[50];
    char phone[15];
    char relation[50];
    struct Contact* next;
}contact;

contact* head=NULL;
void addcontact();
void deletecontact();
void searchcontact();
void modifycontact();
void savecontact();
void loadcontact();
void sortcontacts();
void listcontacts();


// its a control panel including all the functions

int main(int argc, char const *argv[])
{
    loadcontact(); //check if we have existed contact
while(1)
 {
	int choose;

		printf("\n====通讯录====\n");
        printf("1. 增加联系人\n");
        printf("2. 删除联系人\n");
        printf("3. 查询联系人\n");
        printf("4. 修改联系人信息\n");
        printf("5. 保存通讯录到文件\n");
        printf("6. 展示通讯录\n");
        printf("7. 退出程序\n");
        printf("请选择操作: ");
        scanf("%d", &choose);

        switch (choose) 
        {
            case 1:
                addcontact();
                break;
            case 2:
                deletecontact();
                break;
            case 3:
                searchcontact();
                break;
            case 4:
                modifycontact();
                break;
            case 5:
                savecontact();
                break;
            case 6:
                listcontacts();
            case 7:
                savecontact(); //save b4 quit
                exit(0);
            default:
                printf("无效的选择，请重新输入。\n");
        }
 }


	return 0;
}

void addcontact()
{
	contact* newcontact=(contact*)malloc(sizeof(contact));

	printf("请输入姓名: ");
    scanf("%s", newcontact->name);
    printf("请输入手机号: ");
    scanf("%s", newcontact->phone);
    printf("请输入关系: ");
    scanf("%s", newcontact->relation);

    newcontact->next=head; //create a head node of contact
    head=newcontact; //add the contact to linked list
    printf("添加成功");
}

void deletecontact()
{
    char name[50];
    printf("请输入要删除的联系人姓名: ");
    scanf("%49s", name);

    contact*current=head;
    contact*previous=NULL;

    while(current!=NULL)
    {
        if(strcmp(current->name,name)==0)//the name is same
         {
            if(previous==NULL) //linked list only has one node
            {
                head=current->next; //directly empty the head(point to NULL)
            }
            else
            {
                previous->next=current->next;
            }

            free(current); //delete the element
            printf("联系人已删除\n");
            return;
         }
          // if the name is not the same then go throuh the linked-list
          previous = current;
          current = current->next; //go through linked-list
    }
       printf("未找到联系人：%s\n", name); //couldn't return in. while ---> doesn't find the same name 
}

void searchcontact()
{
    char name[50];
    printf("请输入要查询的联系人姓名");
    scanf("%s", name);

    contact*current=head;

    while(current!=NULL)
    {
        if(strcmp(current->name,name)==0)
            {
                printf("姓名: %s\n", current->name);
                printf("手机号: %s\n", current->phone);
                printf("关系: %s\n", current->relation);
                return;
            }
            current=current->next;
    }

    printf("未找到联系人：%s\n", name);
}

void modifycontact()
{
    char name[50];
    printf("请输入要修改的联系人姓名: ");
    scanf("%s", name);

    contact*current=head;

    while(current!=NULL)
    {
        if(strcmp(current->name, name) == 0)
        {
            printf("请输入新手机号:\n ");
            scanf("%s", current->phone);
            printf("请输入新关系:\n ");
            scanf("%s", current->relation);
            printf("联系人已更新\n");
            return;
        }
        current=current->next;
    }
    printf("未找到联系人：%s\n",name);
}

void savecontact()
{
    FILE*file=fopen("/Users/jolin/Documents/GitHub/KJ-NOTE/通訊錄項目/contactlist.txt","w");
    if(file)
    {
        contact*current=head;
        while(current!=NULL)
        {
            fprintf(file, "%s %s %s\n", current->name, current->phone, current->relation);
            current = current->next;
        }
        fclose(file);
        printf("通讯录已保存\n");
    }
    else
    {
        printf("文件出错");
        return;
    }
}

void loadcontact()
{
     FILE* file = fopen("/Users/jolin/Documents/GitHub/KJ-NOTE/通訊錄項目/contactlist.txt", "r");

     if(file!=NULL)
     {
        char name[50];
        char phone[15];
        char relation[50];

        while(fscanf(file,"%s %s %s\n",name,phone,relation)==3)//is already pointer
        {
            contact*newcontact=(contact*)malloc(sizeof(contact));
            strcpy(newcontact->name, name);
            strcpy(newcontact->phone, phone);
            strcpy(newcontact->relation, relation);
            newcontact->next=head;
            head=newcontact; //take the linked list out from the file as contact
        }
        fclose(file);
     }
     else
     {
         printf("无法打开文件。\n");
        return;
     }
}

void listcontacts() 
{
    if (head == NULL) 
    {
        printf("通讯录为空。\n");
        return;
    }

    contact* current = head;
    printf("\n通讯录列表:\n");
    while (current != NULL) 
    {
        printf("姓名: %s\n", current->name);
        printf("手机号: %s\n", current->phone);
        printf("关系: %s\n", current->relation);
        current = current->next;
    }
}