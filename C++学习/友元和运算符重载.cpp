#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//友元实现
//全局函数、友元类、成员函数

//class house
//{
//	friend void goodfriend();
//public:
//	house()
//	{
//		sittingroom = "客厅";
//		bedroom = "卧室";
//	}
//	string sittingroom;
//private:
//	string bedroom;
//};


//void goodfriend()
//{
//	house house1;
//	cout << "进入" << house1.sittingroom << endl;
//	cout << "进入" << house1.bedroom << endl;
//}

//int main()
//{
//	goodfriend();
//	char arr[] = "www\0www";
//	printf("%d", sizeof(arr));
//	printf("\a\a\a\a");
//}

//运算符重载

//1、加号运算符重载


//class person
//{
//public:
//	person operator+ (person& p)
//	{
//		person tmp;
//		tmp.m_age = this->m_age + p.m_age;
//		return tmp;
//	}
//	int GetAge()
//	{
//		return m_age;
//	}
//private:
//	int m_age = 10;
//};

//class person
//{
//public:
//	friend person operator+(const person& p1, const person& p2);
//	int GetAge()
//	{
//		return m_age;
//	}
//private:
//	int m_age = 10;
//};


//person operator+(const person& p1, const person& p2)
//{
//	person tmp;
//	tmp.m_age = p1.m_age + p2.m_age;
//	return tmp;
//}

//void test1()
//{
//	person p1;
//	person p2;
//	person p3 = p1 + p2;
//	//实质为
//	//person p3 = p1.operator+(p2);这是成员函数实现
//	//全局函数实现时，实质为
//	//person p3 = operator+(p1,p2);
//	cout << p3.GetAge() << endl;//输出20
//}

//2、左移运算符重载(打印时只能用全局函数)

//class person
//{
//public:
//	int m_age = 10;
//};

//此处需要返回值必须是引用

//ostream& operator<<(ostream& cout,person& p)
//{
//	cout << p.m_age;
//	return cout;
//}

//void test2()
//{
//	person p;
//	cout << p<<" hello world"<<endl;
//}

//3、函数调用运算符重载（仿函数）


class My_Add
{
public:
	int operator()(int x, int y)
	{
		return x + y;
	}
};

void test3()
{
	//匿名对象调用仿函数
	cout<<My_Add()(100, 200)<<endl;
}

int main()
{
	//test1();
	//test2();
	test3();
}