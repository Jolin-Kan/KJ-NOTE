//recursion 1,1,2,3,5,8,13...
#include <stdio.h>

int F(int n);
int max(int arr[],int n);
int main(int argc, char const *argv[])
{
	printf(" F(1)=%d\n", F(1));
	printf(" F(6)=%d\n", F(6));
	printf("F(10)=%d\n", F(10));

	int arr[9]={1,2,3,4,5,6,7,8,9};
	int n=6;
	printf("max(arr,%d)=%d", n,max(arr,n-1));

	return 0;
}
int F(int n)
{
	if(n==1)
	 return 1;
	else if(n==2)
	 return 1;

	else
		return F(n-2)+F(n-1);

}

int max(int arr[],int n) //保证一定return
{
	
	if(n==0)
		return arr[0];

	int prevMax = max(arr, n - 1); // 递归调用找到前n-1个元素中的最大值
    
    if (prevMax > arr[n])
        return prevMax;
    else
        return arr[n];
}