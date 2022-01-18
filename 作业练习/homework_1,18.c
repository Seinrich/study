#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>

//int is_prime(int n)
//{
//	int i = 2;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}

//int IsLeapYear(int year)
//{
//	return((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
//}

//void Swap(int* pa, int* pb)
//{
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}

////void PrintMulTable(int n)
////{
////	int i = 0;
////	for (i = 1; i <= n; i++)
////	{
////		int j = 0;
////		for (j = 1; j <= i; j++)
////		{
////			printf("%d*%d=%-3d", j, i, j * i);
////		}
////		printf("\n");
////	}
////}

//void test2()
//{
//	int year = 0;
//	while (scanf("%d", &year) != EOF)
//	{
//		if (1 == IsLeapYear(year))
//		{
//			printf("%d是闰年\n",year);
//		}
//		else
//		{
//			printf("%d不是闰年\n",year);
//		}
//	}
//}

//void test1()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i))
//		{
//			printf("%d ", i);
//		}
//	}
//}

//void test3()
//{
//	int x = 4, y = 5;
//	Swap(&x, &y);
//	printf("交换后x=%d y=%d", x, y);
//}

//void test4()
//{
//	int n = 0;
//	scanf("%d", &n);
//	PrintMulTable(n);
//}

//int main()
//{
//	int a = 1;
//	a +=	 a;
//	test4();
//	//test3();
//	//test2();
//}

//int main()
//{
//	int i = 0;
//	int j = 2;
//	int a = 3;
//	a = a + a == i;
//	i += (i = j) + (a = i);
//	printf("%d",i);
//}