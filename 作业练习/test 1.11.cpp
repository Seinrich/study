#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Max(int x, int y)
{
	return x > y ? x : y;
}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("最大值是 %d\n", Max(a, b));
//
//}

int main()
{
	int a = 0;
	int b = 0;
	int i = 0;
	int j = 0;
	scanf("%d %d", &a, &b);
	for (i = 0; i <= a; i++)
	{
		for (j = 0; j <= a; j++)
		{
			if (a == i + j && b == 2 * i + 4 * j)
			{
				printf("%d %d", i, j);
			}
		}
	}
}