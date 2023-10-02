#include <stdio.h>


int main(int agrc, const char* agrv[])
{
	int year, month, date,day;
    int choice; //紀錄用戶的選擇

    
        printf("==== 萬年曆菜單 ====\n");
        printf("1. 顯示日曆\n");
        printf("2. 退出\n");
        printf("（只需要輸入1或2）\n");
        printf("請選擇操作:" );
        scanf("%d", &choice);

        if(choice == 1)
        {
        	printf("請輸入年份：");
        	scanf("%d",&year);

        	printf("請輸入月份：");
        	scanf("%d",&month);

        	printf("請輸入天數：");
        	scanf("%d",&day);

        	if(year>0)
        	{
        		if(month>0&&month<13)
        		{
        			if(day>0&&day<32)
        			{
        				int daysofmonth=0;
                        int monthsday[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
                        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                        {
                            if(month==2)
                            {
                                daysofmonth=29;
                            }
                            
                        }
                        else
                        {
                           daysofmonth=monthsday[month];
                        }

                        printf("there is %d days in this month\n", daysofmonth);
                        
        			}
        		else
        		{
        			printf("error");
        		}

        		}
        	else
        		{
        			printf("error");
        		}
        	}
        	else
        	{
        		printf("error");
        	}
        	


        }
        return 0;

}