#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//递归正序打印数字的每一位

//void Print(int num)
//{
//	if (num / 10)
//	{
//		Print(num/10);
//	}
//	printf("%d ", num % 10);
//}

//void test01()
//{
//	int num = 0;
//	scanf("%d", &num);
//	Print(num);
//}

//递归求n的阶乘

//int FacRecursion(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * FacRecursion(n - 1);
//	}
//}

//void test02()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", FacRecursion(n));
//}

//迭代求n的阶乘

//int FacIteration(int n)
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	return ret;
//}

//void test03()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", FacIteration(n));
//}

//迭代模拟strlen

//int MyStrlenIteration(char* str)
//{
//	int count = 0;
//	while (*str!='\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}

//void test04()
//{
//	char arr[] = "2230wadioj";
//	printf("%d", MyStrlenIteration(arr));
//}

//递归模拟strlen

//int MyStrlenRecursion(char* str)
//{
//	if (*str != '\0')
//	{
//		return 1 + MyStrlenRecursion(str + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}

//void test05()
//{
//	char arr[] = "2230wadioj";
//	printf("%d", MyStrlenRecursion(arr));
//}

//递归实现字符串逆序

//void MyReverseStr(char* str)
//{
//	int len = MyStrlenIteration(str);
//	char tmp = *str;
//	*str = str[len - 1];
//	str[len - 1] = '\0';
//	if (MyStrlenIteration(str) > 1)
//	{
//		MyReverseStr(str + 1);
//	}
//	str[len - 1] = tmp;
//
//}

//void test06()
//{
//	char arr[] = "123456";
//	MyReverseStr(arr);
//	printf("%s\n", arr);
//	char arr1[] = "1234";
//	MyReverseStr(arr1);
//	printf("%s", arr1);
//}

//计算一个非负数的每位之和（递归实现）

//int DigitSum(unsigned int n)
//{
//	if (n)
//	{
//		return n % 10 + DigitSum(n / 10);
//	}
//	else
//	{
//		return n % 10;
//	}
//}

//void test07()
//{
//	unsigned int n = 10245;
//	printf("%d", DigitSum(n));
//}

//递归实现n的k次方
double MyPow(int n, int k)
{
	if (n == 0 && k == 0)
	{
		printf("表达式非法\n");
		return -1;
	}
	if (k == 0)
	{
		return 1;
	}
	else if(k>0)
	{
		return n * MyPow(n, k - 1);
	}
	else
	{
		int preret = (n * MyPow(n, k + 1));
	}
}

void test07()
{
	int n = 0;
	int k = 0;
	scanf("%d%d", &n, &k);
	printf("%lf",MyPow(n, k));
}

int main()
{
	test07();
	//test06();
	//test05();
	//test04();
	//test03();
	//test02();
	//test01();
}