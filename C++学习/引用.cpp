#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
//using namespace std;

//int& test()
//{
//	int b = 0;
//	static int& a = b;
//	return a;
//}

//int main()
//{
//	//允许不同变量引用同一变量，但不允许引用变量指向其他变量
//	//本质上是指针
//	int a = 0;
//	int i = 0;
//	int& b = a;
//	int& c = a;
//	//返回引用的函数可作为左值调用
//	test() = 1;
//}


//void fun(int b ,int a)
//{
//	cout << "fun()" << endl;
//	return;
//}
//
//void fun(int a, int b)
//{
//	cout << "fun(int)" << endl;
//}
//
//int main()
//{
//	fun(10, 10);
//}

//void fun(const int& b)
//{
//	std::cout << "b=" << b << std::endl;
//}

//c++允许结构体中出现函数，c不允许
//struct app
//{
//	int a;
//	int add()
//	{
//		return a;
//	}
//};

//int main()
//{
//	int a = 0;
//	a = 10;
//}