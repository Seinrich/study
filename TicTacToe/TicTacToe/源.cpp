#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,7,5,3};
	int i = 0;
	int sz = sizeof(arr)/ sizeof(arr[0])-1;
	for (; i < sz; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			int tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
	}
	int j = 0;
	for (j; j < sz; j++)
	{
		printf("%d", arr[j]);
	}
}