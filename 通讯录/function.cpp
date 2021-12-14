#define _CRT_SECURE_NO_WARNINGS 1

#include "address list.h"

void menu()
{
	printf("通讯录1.10\n这是正在开发的通讯录，目前是测试版\n");
	printf("目前有如下功能:\n");
	printf("************************************************\n");
	printf("1.创建联系人  2.查找联系人  3.删改联系人  4.排序联系人\n");
	printf("请选择:>");
}

void Creat_New()
{
	contact* ps = (contact*)malloc(sizeof(contact));
	if (ps == NULL)
	{
		perror("ps指针出错了，请联系我");
		return;
	}
	else
	{
		ps->person = (PeopleInform*)malloc(sizeof(PeopleInform));
		if (ps->person == NULL)
		{
			perror("person指针出错了，请联系我");
		}
		else
		{
			int is_right = 0;
			while (is_right)
			{
				printf("请输入联系人姓名(最多二十个字符):>");
				scanf("%s", ps->person->name);
				if (strlen(ps->person->name) > 20||strlen(ps->person->name)>11)
					printf("超过最大限度，请重新输入\n");
				else
				{
					printf("请输入联系人电话(非大陆请加上0x):>");
					scanf("%s", ps->person->tel);
					if (strlen(ps->person->tel) > 13)
					{
						printf("超过最大限度，请重新输入\n");
					}
					else
					{
						is_right = 1;
						printf("创建成功");
						ps->count++;
					}
				}
			}
		}
	}
}