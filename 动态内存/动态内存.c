#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

////int main()
////{
////	int* p = (int*)malloc(INT_MAX);
////	if (p == NULL)
////	{
////		printf("%s\n", strerror(errno));
////	}
////}
// 
////题目1：下面程序运行结果
//
////void GetMemory(char* p)
////{
////	p = (char*)malloc(100);
////}
////void test()
////{
////	char* str = NULL;
////	GetMemory(str);
////	strcpy(str, "hello world");
////	printf(str);
////}
////int main()
////{
////	test();
////}
////程序崩溃，因为对空指针进行了解引用，str传参时传的是值

