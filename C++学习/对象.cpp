#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

//对象模型

//class p
//{
//	//类也需要内存对齐，占用空间为最大对齐数的整数倍
//	//计算大小的方法同结构体
//	char b;
//	char k;
//	int m;
//	char n;
//	int a;
//};

//int main()
//{
//	p pe;
//	std::cout << sizeof(pe);
//}

//this指针，该指针由编译器产生

//class person
//{
//public:
//	void InitAge(int m_age)
//	{
//		//m_age = m_age;//此时形参与成员名相同，导致赋值时不能赋值给成员
//		this->m_age = m_age;//用this指针来进行区分，可对成员赋值
//	}
//
//	//当返回值类型不是引用时，函数结束后相当于新创建了一个对象
//	
//	//person AddAge(int m_age)
//	//{
//	//	//返回this指向的对象
//	//	this->m_age += m_age;
//	//	return *this;
//	//}
//
//	//返回引用时，返回的是this指向的对象本身
//	person& AddAge(int m_age)
//	{
//		//返回this指向的对象
//		this->m_age += m_age;
//		return *this;
//	}
//
//
//	int GetAge()
//	{
//		return m_age;
//	}
//
//private:
//	int m_age;
//};

//int main()
//{
//	person A1;
//	A1.InitAge(5);
//	//链式访问
//	A1.AddAge(10).AddAge(10).AddAge(10);
//	std::cout << A1.GetAge() << std::endl;//当addage返回值不是引用时，输出15，是引用时返回35
//}

//class person
//{
//	void mai()
//	{
//		
//	}
//	int a;
//	int b;
//};

int main()
{
	int size = 2;
	int* p = new int[size];
	p[0] = 1;
	p[1] = 1;
}
