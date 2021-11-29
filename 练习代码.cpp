#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <array>

//猜数字
//int menu()
//{
//	again:
//	int a = 0;
//	printf("欢迎来到猜数字游戏\n");
//	printf("1.play      0.exit\n");
//	printf("请您选择:");
//	scanf("%d", &a);
//	if (a != 0 && a != 1)
//	{
//		printf("重新输入:");
//		goto again;
//	}
//	return a;
//}
//
//void game(int* ret)
//{
//	printf("请猜数字");
//	int guess = 0;
//	for (;guess!=*ret;)
//	{
//		scanf("%d", &guess);
//		if (guess > *ret)
//		printf("猜大咯！再试试:");
//		if (guess < *ret)
//		printf("猜小咯！再试试:");
//		if (guess == *ret)
//		printf("猜对啦！\n");
//	}
//	system("pause");
//}
//
//int main()
//{
//	int ret = 0;
//	int choose = menu();
//	srand((unsigned int)time(NULL));
//	do
//	{
//		ret = rand()%100+1;
//		game(&ret);
//		printf("游戏结束，1.重新开始  0.退出游戏\n请选择哦:");
//		scanf("%d", &choose);
//	} while (choose);

//冒泡排序
//void Bubble_sorting(int* arr,int sz)
//{
//	int i = 0;
//	for (; i < sz; i++)
//	{
//		int j = 0;
//		for (; j < sz-1; j++)
//		{
//			if ((arr[j]) > (arr[j + 1]))
//			{
//				int tmp = arr[j+1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[5] = {};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz; i++)
//	{
//		int a = 0;
//		printf("请输入一个数字:\n");
//		scanf("%d", &a);
//		arr[i] = a;
//	}
//	Bubble_sorting(arr,sz);
//	for (int i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//}

//void init(int* arr, int sz)
//{
//	int i = 0;
//	for (; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void print(int* arr, int sz)
//{
//	int i = 0;
//	for (; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void reverse(int* arr, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main()
//{
//	int arr[10];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	init(arr,sz);
//	print(arr, sz);
//	reverse(arr, sz);
//}

//int main()
//{
//	int arr1[] = { 1,3,5,7,9 };
//	int arr2[] = { 2,4,6,8,0 };
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (; i < sz; i++)
//	{
//		int tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	for (i=0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//		
//	for (i=0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//}

//int main()
//{
//	int arr[5] = {};
//	int i = 0;
//	for (; i < 5; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i=0; i < 5; i++)
//	{
//		printf("%d", arr[i]);
//	}
//}

//求二进制补码中1的个数

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int b = 1; //0001 0010
//	int count = 0;
//	int c = 0;
//	for (int i = 0; i < 32; i++)
//	{
//	    c = a & b;
//		if (c == 1)
//		{
//			count++;
//		}
//		a=a >> 1;
//	}
//	printf("%d", count);

////0001 0010 
////0011
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a,&b);
//	int c = a^b;
//	int count = 0;
//	while (c)
//	{
//		count++;
//		c = c & (c - 1);
//	}
//	printf("%d", count);
//}

//交换两个变量内容，不创建第三变量

//int main()
//{
//	int a = 1;//0001
//	int b = 3;//0011
//	a = a ^ b;//0010
//	b = a ^ b;//0001
//	a = a ^ b;//0011
//	printf("a=%d,b=%d", a, b);
//}

//指针打印数组

//int main()
//{
//	int arr[10] = { 1,3,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	int i = 0;
//	for (; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//}

//打印乘法表

//int main()
//{
//	int i = 0, j = 0,row=0;
//	scanf("%d", &row);
//	for (i = 1; i <= row; i++)
//	{
//		for (j = 1; j <=i; j++)
//		{
//			printf("%d*%d=%-3d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//}


//递归打印数字每一位

//void print(int a)
//{
//	if (a != 0)
//	{
//		print(a / 10);
//		printf("%d ", a%10);
//	}
//}

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	print(a);
//}

//递归求n的阶乘

//int Factorial(int n)
//{
//	int tmp = 1;
//	if (n != 0)
//	{
//		tmp = n * Factorial(n - 1);
//	}
//	return tmp;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = Factorial(n);
//	printf("%d", sum);
//}

//非递归

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int tmp = 1;
//	for (i=1; i <= n; i++)
//	{
//		tmp = tmp * i;
//	}
//	printf("%d", tmp);
//}


//int main()
//{
//	char arr[] = "abcde";
//	printf("%d\n", sizeof(arr));
//	printf("%d\n", strlen(arr));
//	char arr1[] = { 'a','b','c','d','e','\0'};
//	printf("%d\n", sizeof(arr1));
//	printf("%d\n", strlen(arr1));
//}

//int sumprint(int a)
//{
//	int sum = 0;
//	if (a != 0)
//	{
//		sum = a % 10+sumprint(a / 10);
//		printf("%d ", a % 10);
//	}
//	return sum;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	a = sumprint(a);
//	printf("\n");
//	printf("sum = %d", a);
//}



//int main()
//{
//	int a = 1;
//	a = a >> 1;
//	printf("%d", a);
//
//}

//int main()
//{
//	int arr[] = { 3,4,5 };
//	int* a = &arr[0];
//	*a++ = 10;
//	printf("%d", arr[0]);
//}