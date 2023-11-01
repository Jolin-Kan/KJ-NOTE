#include <stdio.h>

int fdayofmo(int year, int month, int day) 
{
    if (month < 3) 
    {
        month += 12;
        year--;
    }
    int wd = (1 + day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    return wd;
}

int main() 
{
    while(1)
    {
    int year, month, day;
    int choice;

    printf("<===== 萬年曆菜單 =====>\n");
    printf("1. 顯示日曆\n");
    printf("2. 退出\n");
    printf("（只需要輸入1或2）\n");
    printf("請選擇操作: ");
    scanf("%d", &choice);

    if (choice == 1) 
    {
        printf("請輸入年份：");
        scanf("%d", &year);

        printf("請輸入月份：");
        scanf("%d", &month);

        printf("請輸入天數：");
        scanf("%d", &day);

        if (year > 0 && month > 0 && month < 13 && day > 0 && day < 32) 
        {
            int daysofmonth = 0;
            int monthsday[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                if (month == 2) 
                {
                    daysofmonth = 29;
                } else {
                    daysofmonth = monthsday[month];
                }
            }
             else 
            {
                daysofmonth = monthsday[month];
            }

            printf("there is %d days in this month\n", daysofmonth);
            printf("%d-%d-%d\n", year, month, day);
            int dayofm = fdayofmo(year, month, 1); // 计算当月第一天是星期几
            printf("#%d\n", dayofm);

            switch (dayofm) 
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

            printf("%d-%d-1\n", year, month);
            printf("#%d\n", dayofm);

            printf("== 日  一  二  三  四  五  六 ==\n");

            int i, j;
            for (i = 0; i < dayofm; i++) 
            {
                printf("    "); // 输出空白，留出日期前的空间
            }

            for (j = 1; j <= daysofmonth; j++) 
            {
                if (j == day) 
                {
                    if (day > 9) 
                    {
                        printf(" *%2d", j); // 标记用户输入的日期
                    } 
                    else 
                    {
                        printf("  *%d", j);
                    }
                } 
                else 
                {
                    if (j > 9)
                     {
                        printf("  %2d", j);
                    } 
                    else 
                    {
                        printf("   %d", j);
                    }
                }

                if ((dayofm + j) % 7 == 0)
                 {
                    printf("\n"); // 换行
                }
            }

            printf("\n");
        } else {
            printf("error");
        }
    } else {
        printf("error");
    }

}
    return 0;
}
