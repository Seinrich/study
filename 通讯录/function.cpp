#define _CRT_SECURE_NO_WARNINGS 1

#include "address list.h"

void menu()
{
	printf("通讯录1.10\n这是正在开发的通讯录，目前是测试版\n");
	printf("目前有如下功能:\n");
	printf("******************************************************************\n");
}

void menu1()
{
	printf("1.创建联系人  2.展示列表  3.查找联系人  4.删改联系人  5.排序联系人\n");
	printf("请选择:>");
}

void Init(contact*ps)
{
	//为联系人数据开辟空间
	ps->person = (PeopleInform*)malloc(DefaultNum*sizeof(PeopleInform));
	if (ps == NULL)
	{
		perror("出错了，请联系我");
		return;
	}
	ps->count = 0;
	ps->capacity = DefaultNum;
}

void Check(contact* ps)
{
	//是否扩容
	if (ps->count == ps->capacity)
	{
		PeopleInform* p = (PeopleInform*)realloc(ps->person,(DefaultNum+Plus)*sizeof(PeopleInform));
		if (p != NULL)
		{
			ps->person = p;
			ps->capacity += Plus;
		}
		else
		{
			perror("扩容失败，请联系我");
		}
	}
}

void Creat_New(contact* ps)
{
	Check(ps);
	int is_right = 1;
	while (is_right)
	{
		printf("请输入联系人姓名(最多二十个字符):>");
		scanf("%s", ps->person->name);
		if (strlen(ps->person->name) > 20)
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
				printf("请输入性别:>");
				scanf("%s", ps->person->sex);
				is_right = 0;
				printf("创建成功!");
				Sleep(1000);
				system("cls");
				ps->person++;
				ps->count++;
			}
		}
	}
}

void Show(contact* ps)
{
	int i = ps->count;
	while (i)
	{
		printf("姓名              电话号码\n");
		printf("%s(%s)%16s\n", ps->person->name, ps->person->sex, ps->person->tel);
		i--;
		ps->person++;
		system("pause");
		system("cls");
	}
}

void Search(contact* ps)
{
	printf("选择查找方式：1.姓名查找 2.姓氏查找:>");
	int choose = 1;
	int whether = 0;
	while (choose)
	{
		scanf("%d", &choose);
		if (choose == 1)
		{
			printf("请输入要查找的联系人的姓名:>");
			char name[nameM] = "";
			scanf("%s", &name);
			int i = ps->count;
			PeopleInform* ptr = ps->person;
			while (i)
			{
				if (0 == (strcmp(name, ptr->name)))
				{
					printf("该联系人信息如下\n");
					printf("姓名              电话号码\n");
					printf("%s(%s)%16s\n", ps->person->name, ps->person->sex, ps->person->tel);
					whether++;
				}
				ptr++;
				i--;
			}
			if (whether == 0)
				printf("该联系人不存在");
			system("pause");
			system("cls");
			break;
		}
		else if (2 == choose)
		{
			printf("请输入要查找的联系人的姓:>");
			char name[nameM] = "";
			scanf("%s", &name);
			int i = ps->count;
			PeopleInform* ptr = ps->person;
			while (i)
			{
				if (0 == strncmp(name, ptr->name, strlen(name)))
				{
					printf("姓名              电话号码\n");
					printf("%s(%s)%16s\n", ps->person->name, ps->person->sex, ps->person->tel);
				}
				ptr++;
				i--;
				whether++;
			}
			if (whether == 0)
				printf("该联系人不存在\n");
			system("pause");
			system("cls");
			break;
		}
		else
		{
			printf("选择错误,重新选择:>");
			choose = 1;
		}
	}
}

void Modify_List(contact* ps)
{
	printf("请输入要查找的联系人的姓名");
	char name[20] = {};
	scanf("%s", &name);
}

