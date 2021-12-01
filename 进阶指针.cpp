#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//char* My_Strcpy(char* dest, const char* src)
//{
//}

//int main()
//{
	//(*printf)("hehe");
	//char* (*pf)(char*, const char*) = My_Strcpy;//函数指针
	//char* (*pfArr[4])(char*, const char*) = {};//函数指针数组
//}

//对qsort的应用及对函数回调的理解


struct stu
{
	char name[20];
	int age;
};

int cmp_int(const void* e1, const void* e2)
{
	return *((int*)e1) - *((int*)e2);
}

void test1()
{
	int arr[] = { 0,3,2,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

int cmp_float(const void* e1, const void* e2)
{
	return (int)(*(float*)e1 - *(float*)e2);
}

void test2()
{
	float arr[] = { 1.0,3.0,2.0,5.4,5.3,6.5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_float);
	int i = 0;
	for (; i < sz; i++)
	{
		printf("%f ", arr[i]);
	}
}

int cmp_struct_by_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

void test3()
{
	struct stu s[3] = { {"xudong",18},{"jiarui",19},{"jiahao",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_struct_by_age);
}

int main()
{
	test1();
	test2();
	test3();
}