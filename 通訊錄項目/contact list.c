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


// its a control panel including all the functions

int main(int argc, char const *argv[])
{
	int choose;

		printf("\n====通讯录====\n");
        printf("1. 增加联系人\n");
        printf("2. 删除联系人\n");
        printf("3. 查询联系人\n");
        printf("4. 修改联系人信息\n");
        printf("5. 保存通讯录到文件\n");
        printf("6. 排序通讯录\n");
        printf("7. 模糊查询\n");
        printf("8. 退出程序\n");
        printf("请选择操作: ");
        scanf("%d", &choose);

        switch (choice) 
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
                updatecontact();
                break;
            case 5:
                savecontactsToFile();
                break;
            case 6:
                sortcontacts();
                break;
            case 7:
                fuzzysearch();
                break;
            case 8:
                savecontactsToFile(); //save b4 quit
                exit(0);
            default:
                printf("无效的选择，请重新输入。\n");
        }


	return 0;
}

void addcontact()
{
	contact* newcontact=(contact)malloc(contact);

	printf("请输入姓名: ");
    scanf("%s", newcontact->name);
    printf("请输入手机号: ");
    scanf("%s", newcontact->phone);
    printf("请输入关系: ");
    scanf("%s", newcontact->relation);

    newcontact->next=head; //create a head node of contact
    head=newcontact; //add the newcontact to linked list
    printf("添加成功");
}

void deletecontact
{
    char name[50];
    printf("请输入要查询的联系人姓名: ");
    scanf("%49s", name);

    contact*current=head;
    contact*previous=NULL;

    while(current!=NULL)
    {
        if(strcmp(current->name,name)==0)//not the same
         {
            if(previous=NULL) //only one node
            {
                head=current->next;
            }
            else
            {
                previous->next=current->next
            }

            free(current); //delete the element
            printf("联系人已删除\n");
            return;
         }
          previous = current;
          current = current->next; //go through linked-list
    }
       printf("未找到联系人：%s\n", name);

}