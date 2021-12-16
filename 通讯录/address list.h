#pragma once

#define nameM 20
#define telM 13
#define sexM 5
#define DefaultNum 2
#define Plus 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

enum address_list
{
	creat = 1,
	show,
	search,
	modify,
	sort,
	special,
};

//联系人的基本结构
typedef struct PeopleInform
{
	char name[nameM];
	char tel[telM];
	char sex[sexM];
}PeopleInform;

//contact结构体，包含基本信息和数量，以及结构体指针
typedef struct Contact
{
    PeopleInform* person;
	int count;//记录所建的联系人数量
	int capacity;//容量记录，超容扩容
}contact;

//调用函数声明

//菜单
void menu();

//菜单1
void menu1();

//初始化结构体
void Init(contact* ps);

//检查是否满员
void Check(contact* ps);

//创建联系人
void Creat_New(contact* ps);

//展示联系人名录
void Show(contact* ps);

//查找联系人
void Search(contact* ps);

//删改联系人
void Modify_List(contact* ps);

//排序
void Sort_List();

void Special();
