/*冒泡排序的C语言实现
冒泡排序指依次比较相邻的两个数据排序*/
#include <stdio.h>

void bubblesort(int arr[],int len);
int main(int argc, char const *argv[])
{
	int arr[]={11,2,3,11,4,4,5,6,44,88,9,44};
	int x;
	int len = (int)(sizeof(arr)/sizeof(*arr));
	bubblesort(arr,len);
	for(int i=0;i<len;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
void bubblesort(int arr[],int len)
{
	int i,j,temp;
	for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
