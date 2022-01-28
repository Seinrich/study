#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//void Print(int* p,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}

//int main()
//{
//	char ch[10000] = "";
//	int i = 0;
//	
//	
//		ch[i] = getchar();
//	
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, sz);
//}



//int Sum(int n)
//{
//	int i = 0;
//	int sum = 0;
//	int nst = n;
//	for (i = 0; i < 5; i++)
//	{
//		if (i >= 1)
//		{
//			nst = nst * 10 + n;
//		}
//		sum += nst;
//	}
//	return sum;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", Sum(n));
//}

//int getnum(int n)
//{
//	return n % 10;
//}

//int Is(int n)
//{
//	int count = 0;
//	int sum = 0;
//	int ncp = n;
//	while (ncp)
//	{
//		count++;
//		ncp /= 10;
//	}
//	ncp = n;
//	while (ncp)
//	{
//		sum += (int)pow(getnum(ncp),count);
//		ncp /= 10;
//	}
//	if (sum == n)
//	{
//		return 1;
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (; i <= 100000; i++)
//	{
//		if (1 == Is(i))
//		{
//			printf("%d ", i);
//		}
//	}
//}

int main()
{
	int i,j;
	for (i = 1;i <= 7; i++)
	{
		for (j = 0; j < 7 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2*(i-1) + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 6; i > 0; i--)
	{
		for (j = 0; j < 7 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * (i - 1) + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}