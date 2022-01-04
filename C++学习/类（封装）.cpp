#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<string>
using namespace std;

class student
{
public:

	string name;
	string stu_num;

	void printStudent()
	{
		cout << "学生姓名为: " << name << endl;
		cout << "他的学号是: " << stu_num << endl;
	}
};


int main()
{
	student a;
	a.name = "张三";
	a.stu_num = "212121";
	a.printStudent();
}