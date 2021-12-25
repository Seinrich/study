#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//1. 切割字符串

//int cmp_int(const void* p1, const void* p2)
//{
//	return *((int*)p1) - *((int*)p2);
//}

//void strtok1(char* str, char* tok)
//{
//	int i = 0;//循环变量,控制tok中的字符
//	int lenstr = strlen(str);
//	int lentok = strlen(tok);
//	int count = 0;
//	int j = 0;//循环变量，控制str中的字符
//	int* pi = (int*)malloc(sizeof(int));
//	for (i = 0; i < lentok; i++)
//	{
//		for (j = 0; j < lenstr; j++)
//		{
//			if (tok[i] == str[j])
//			{
//				count++;//count是pi数组中的元素个数
//				str[j] = '\0';
//				int* ptr = (int*)realloc(pi, sizeof(int) * count);
//				if (ptr)
//				{
//					pi = ptr;
//					pi[count - 1] = j;//要额外+1才能指向\0后面
//				}
//			}
//		}
//	}
//	char* pt = str;//作为str的副本，不损伤str
//	printf("%s\n", pt);
//	if (count > 1)
//	{
//		qsort(pi, count, sizeof(int), cmp_int);
//	}
//	for (i = 0; i <= count - 1; i++)
//	{
//		pt = str;
//		pt += pi[i] + 1;
//		if (pt[pi[i]] == pt[pi[i] + 1])
//		{
//			continue;
//		}
//		printf("%s\n", pt);
//	}
//}

//int main()
//{
//	char str[81] = "";
//	gets_s(str);
//	char tok[81] = "";
//	gets_s(tok);
//	strtok1(str, tok);
//}

//2. 消失的数字（数组中有0到n的整数，缺了一个，找出来）

//猜测：异或操作满足结合律，交换律
//异或操作，同0异1

//int missingnumber(int* pi,int n)
//{
//	int a = 0;
//	int i = 0;
//	for (i = 0; i <= n; i++)
//	{
//		a = a ^ i;
//	}
//	for (i = 0; i < n; i++)
//	{
//		a = a ^ pi[i];
//	}
//	return a;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,9,0 };
//	int n = 9;//0到9，可输入实现
//	printf("%d",missingnumber(arr,n));
//}

//3. 一个单身狗（数组中有一个单独的整数，其他的都出现两次，时间复杂度为O（n）法同上）

//4. 两个单身狗(时间复杂度为O（n）)

//void singlenum(int* pi, int sz)
//{
//	int i = 0;//循环变量
//	int a = 0;//异或变量
//	int b = 1;//判断二进制位是否为1
//	int* p1 = (int*)malloc(sizeof(int)*(sz-1));
//	int count1 = 0;
//	int* p0 = (int*)malloc(sizeof(int)*(sz-1));
//	int count0 = 0;
//	//数组中的元素全部异或，最终得到两个单独数的异或值
//	if (p1 && p0)
//	{
//		for (i = 0; i < sz; i++)
//		{
//			a = a ^ pi[i];
//		}
//		//找两个单独数异或值的倒数第几位是1（因为异或处是1的，证明二者在此处二进制位不同）
//		for (i = 0; i < 32; i++)
//		{
//			if ((a & b) == 1)
//			{
//				int j = 0;//二次循环，判断数组中倒数第i+1位的二进制位是否是1，是1和不是1的分两组
//				for (j = 0; j < sz; j++)
//				{
//					if (((pi[j] >> i) & b) == 1)
//					{
//						count1++;
//						p1[count1 - 1] = pi[j];
//					}
//					else
//					{
//						count0++;
//						p0[count0 - 1] = pi[j];
//					}
//				}
//				break;//if条件成功一次就可以，多次重复无意义，还可能出bug
//			}
//			a = a >> 1;
//		}
//		int m = 0;//异或变量，求出单独的两数字其中的一个数字
//		int n = 0;//异或变量，求出单独的数字的另一个
//		for (i = 0; i < count0; i++)
//		{
//			m = m ^ p0[i];
//		}
//		for (i = 0; i < count1; i++)
//		{
//			n = n ^ p1[i];
//		}
//		if (count0 % 2 == 0)
//		{
//			printf("没有两个单身狗");
//			return;
//		}
//		printf("%d %d", n, m);
//	}
//}

//int main()
//{
//	int arr[] = { 1,1,3,3,4,4,5,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	singlenum(arr, sz);
//}