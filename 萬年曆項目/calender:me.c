#include <stdio.h>


int fdayofmo(int year,int month,int day)    //根據互聯網搜索蔡勒公式判斷某一天是星期幾
{
   if(year>1583 && month > 9)
                        {
                            if(day>3)
                            {
                                return (day + 1 + (2 * month) + ((13 * (month + 1)) / 5) + year + (year / 4) - (year / 100) + (year / 400)) % 7;
                            }  
                             else 
                        {
                            return (day + 1 + (2 * month) + ((13 * (month + 1)) / 5) + year + (year / 4) + 5) % 7;
                        }   
                        //
                        }      
                        else 
                        {
                            return (day + 1 + (2 * month) + ((13 * (month + 1)) / 5) + year + (year / 4) + 5) % 7;
                        }    
}



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

            int oday=day; //儲存輸入的天數

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
                            else
                            {
                                daysofmonth=monthsday[month];
                            }
                            
                        }
                        else
                        {
                           daysofmonth=monthsday[month];
                        }

                        printf("there is %d days in this month\n", daysofmonth);
                        printf("%d-%d-%d\n", year,month,day);
                         int dayofm = fdayofmo(year,month,day);    //引用自定函數計算當天是星期幾

                        switch(dayofm)
                        {
                        case 0:
                            printf("this day is sunday\n");
                            break;
                        case 1:
                            printf("this day is monday\n");
                            break;
                        case 2:
                            printf("this day is thuesday\n");
                            break;
                        case 3:
                            printf("this day is wednesday\n");
                            break;
                        case 4:
                            printf("this day is thursday\n");
                            break;
                        case 5:
                            printf("this day is friday\n");
                            break;
                        case 6:
                            printf("this day is saturday\n");
                            break;
                        }  
                        
                        day=1;
                        /////        //計算當月第一天是星期幾，便於畫日曆
                        printf("%d-%d-%d\n", year,month,day); 
                        int fdayofm = fdayofmo(year,month,day); 

                        switch(fdayofm) //第一天的星期數 決定第一次print的格式
                        {
                        case 0:
                            printf("The day of the first date is sunday\n");
                            break;
                        case 1:
                            printf("The day of the first date is monday\n");
                            break;
                        case 2:
                            printf("The day of the first date is thuesday\n");
                            break;
                        case 3:
                            printf("The day of the first date is wednesday\n");
                            break;
                        case 4:
                            printf("The day of the first date is thursday\n");
                            break;
                        case 5:
                            printf("The day of the first date is friday\n");
                            break;
                        case 6:
                            printf("The day of the first date is saturday\n");
                            break;
                        }
                        day=oday;

                    printf("== 日  一  二  三  四  五  六 ==\n");
                    //*
                    int cnt=0,i=1;
                    while(cnt<((3*fdayofm)+4)) //空格輸入數量公式
                     {
                        printf(" ");
                        cnt++;
                     }
                     printf("%d",i);
                     //*
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