#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//笔试题目

int main()
{
	//int arr[3][2] = { (0,1),(2,3),(4,5) };
	//赋值语句为逗号表达式，为最后的值
	//实际赋值1，3，5，后面三个元素默认为0
	//int a[3][2] = { {1,2},{3,4},{5,6} };
	//完全赋值
	//或写为{1,2,3,4,5,6}

	//题目1
	//int arr[3][2] = { (0,1),(2,3),(4,5) };
	//int* p;
	//p = arr[0];
	//printf("%d", p[0]);
	//p[0]相当于*(p+0),结果为1

	//题目2(难度较大）
	//int a[5][5];
	//int(*p1)[4];
	//p1 = a;
	//printf("%p,%d\n", &p1[4][2] - &a[4][2], &a[4][2] - &p1[4][2]);
	//本编译器强行赋值无法编译，若可行，理论结果为
	//0xFFFFFFFC ， -4
	
	//题目3
	//int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	//int* ptr1 = (int*)(&aa + 1);
	//int* ptr2 = (int*)(*(aa + 1));//此处的强制类型转换是多余的
	//printf("%d,%d",*(ptr1-1),*(ptr2-1));
	// 10 5

	//题目4
	/*const char* a[] = { "work","at","alibaba" };
	const char** pa = a;
	pa++;
	printf("%s\n", *pa);*/
	//at

	//题目5(难度较大，画内存布局利于解决)
	const char* c[] = { "ENTER","NEW","POINT","FIRST" };
	const char** cp[] = { c + 3,c + 2,c + 1,c };
	const char*** cpp = cp;

	printf("%s\n", **++cpp);//POINT
	printf("%s\n", *--*++cpp+3);//ER
	printf("%s\n", *cpp[-2]+3);//ST
	printf("%s\n", cpp[-1][-1]+1);//EW
}