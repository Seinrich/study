#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	for (i = 1; i <= 9; i++)
	{
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-3d", i, j, i * j);
		}
		printf("\n");
	}
}

//int cmp(const int* x, const int* y)
//{
//	return(*x - *y);
//}

//int main()
//{
//	int arr[10];
//	int i = 0;
//	for (; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, 10, 4, cmp);
//	printf("%d", arr[9]);
//}

//int main()
//{
//	double sum = 0;
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 != 0)
//		{
//			sum += 1.0 / i;
//		}
//		else
//		{
//			sum -= 1.0 / i;
//		}
//	}
//	printf("%lf", sum);
//}

//int main()
//{
//	int num = 1;
//	int count = 0;
//	for (num = 1; num <= 100; num++)
//	{
//		int copy = num;
//		while (copy)
//		{
//			if (copy % 10 == 9)
//			{
//				count++;
//			}
//			copy /= 10;
//		}
//	}
//	printf("%d", count);
//}

//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		if (i % j != 0)
//		{
//			printf("%d ", i);
//		}
//	}
//}

//int main()
//{
//	int year = 1000;
//	for (; year <= 2000; year++)
//	{
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
//		{
//			printf("%d ", year);
//		}
//	}
//}

//int MaxComMultiple(int x ,int y)
//{
//	int remainder = 0;
//	while (1)
//	{
//		if (x > y)
//		{
//			remainder = x % y;
//			x = remainder;
//			if (remainder == 0)
//			{
//				return y;
//			}
//		}
//		else
//		{
//			remainder = y % x;
//			y = remainder;
//			if (remainder == 0)
//			{
//				return x;
//			}
//		}
//	}
//}

//int main()
//{
//	int num1 = 0;
//	int num2 = 0;
//	while (1)
//	{
//		scanf("%d%d", &num1, &num2);
//		if (num1 >0 && num2 > 0)
//		{
//			break;
//		}
//	}
//
//	int val = MaxComMultiple(num1, num2);
//	printf("%d", val);
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//}

//int main()
//{
//	int x, y, z;
//	scanf("%d%d%d", &x, &y, &z);
//	if (x > y)
//	{
//		if (x > z)
//		{
//			if (y > z)
//			{
//				printf("%d %d %d", x, y, z);
//			}
//			else
//			{
//				printf("%d %d %d", x, z, y);
//			}
//		}
//		else
//		{
//			printf("%d %d %d", z, x, y);
//		}		
//	}
//	else
//	{
//		if (y > z)
//		{
//			if (x > z)
//			{
//				printf("%d %d %d", y, x, z);
//			}
//			else
//			{
//				printf("%d %d %d", y, x, z);
//			}
//		}
//		else
//		{
//			printf("%d %d %d", z, y, x);
//		}
//	}
//}

//

//int Max(int x, int y)
//{
//	return x > y ? x : y;
//}
//
////int main()
////{
////	int a = 0;
////	int b = 0;
////	scanf("%d %d", &a, &b);
////	printf("最大值是 %d\n", Max(a, b));
////
////}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int i = 0;
//	int j = 0;
//	scanf("%d %d", &a, &b);
//	for (i = 0; i <= a; i++)
//	{
//		for (j = 0; j <= a; j++)
//		{
//			if (a == i + j && b == 2 * i + 4 * j)
//			{
//				printf("%d %d", i, j);
//			}
//		}
//	}
//}
