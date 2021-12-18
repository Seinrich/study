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
	ps->person += ps->count;//调整person指针位置到无数据处(必须在check之后)
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
				ps->person++;
				ps->count++;
			}
		}
	}
	ps->person -= ps->count;//调整person指针到初始处
	system("cls");
}

void Show(contact* ps)
{
	int i = ps->count;
	printf("姓名              电话号码\n");
	while (i)
	{
		printf("%s(%s)%16s\n", ps->person->name, ps->person->sex, ps->person->tel);
		i--;
		ps->person++;
	}
	system("pause");
	system("cls");
	ps->person -= ps->count;//让ps指向的person指针回归到最初位置
}

void Search(contact* ps)
{
	printf("选择查找方式：1.姓名查找 2.姓氏查找:>");
	int choose = 1;
	int whether = 0;//用来判断是否能找到联系人
	while (choose)
	{
		scanf("%d", &choose);
		if (choose == 1)
		{
			printf("请输入要查找的联系人的姓名:>");
			char name[nameM] = "";
			scanf("%s", &name);
			int i = ps->count;
			while (i)
			{
				if (0 == (strcmp(name, ps->person->name)))
				{
					whether++;
					if (whether == 1)//为了只打印一次
					{
						printf("联系人信息如下\n");
						printf("姓名              电话号码\n");
					}
					printf("%s(%s)%16s\n", ps->person->name, ps->person->sex, ps->person->tel);
					
				}
				ps->person++;
				i--;
			}
			if (whether == 0)
				printf("该联系人不存在\n");
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
			while (i)
			{
				
				if (0 == strncmp(name, ps->person->name, strlen(name)))
				{
					whether++;
					if (whether == 1)//只打印一次，免重复
					{
						printf("联系人信息如下\n");
						printf("姓名              电话号码\n");
					}
					printf("%s(%s)%16s\n", ps->person->name, ps->person->sex, ps->person->tel);
				}
				ps->person++;
				i--;
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
	ps->person -= ps->count;//让ps指向的person指针回归到最初位置
}

void Modify_List(contact* ps)
{
	printf("请输入要修改的联系人姓或姓名\n");
	//在联系人列表中开始查找，但方法不同与search,所以没有直接调用
	char name[nameM] = "";
	char tel[telM] = "";
	char sex[sexM] = "";
	scanf("%s %s %s", &name,&tel,&sex);

	int i = ps->count;//避免修改count值

	int whether = 0;//用以判断能否找到及控制打印

	//记录下来符合条件的所有联系人地址，放进数组里
	PeopleInform** p = (PeopleInform**)malloc(sizeof(PeopleInform));
	if (p != NULL)
	{
		//打印全部符合条件的联系人（删除重复创建？。。。感觉可以在创建时禁止，但是快写完了，不改了）
		while (i)
		{
			//if条件，判断姓名性别电话是否相符
			if (0 == strncmp(name, ps->person->name,strlen(name)))
			{
				whether++;
				if (whether == 1)
				{
					printf("找到如下联系人");
					printf("  姓名              电话号码\n");
				}
				printf("%d %s(%s)%16s\n", whether,ps->person->name, ps->person->sex, ps->person->tel);
				PeopleInform** ptr = (PeopleInform**)realloc(p, whether * sizeof(PeopleInform));
				if (ptr != NULL)
				{
					p = ptr;
					p[whether - 1] = ps->person;//记录找到的联系人所存信息的地址（我太难了）
				}
			}
			ps->person++;//ps指针指到最后位置
			i--;
		}
	}
	if (whether >= 1)
	{
		int a = 0;
		printf("请选择要修改的联系人（输入前面的数字）:>");
		scanf("%d", &a);
		printf("锁定联系人:>\n");
		printf("%s(%s)%16s\n", p[a-1]->name, p[a-1]->sex, p[a-1]->tel);
		int mod = 4;
		printf("请输入要修改的内容\n");
		printf("1.姓名 2.电话 3.性别 4.删除(还没实现) 0.退出");
		while (mod)
		{
			printf("请选择:>");
			scanf("%d", &mod);
			if (mod == 1)
			{
				char name[nameM] = "";
				scanf("%s", p[a-1]->name);
				printf("修改成功");
			}
			else if (mod == 2)
			{
				char tel[telM] = "";
				scanf("%s", p[a - 1]->tel);
				printf("修改成功");
			}
			else if (mod == 3)
			{
				char sex[sexM] = "";
				scanf("%s", p[a - 1]->sex);
				printf("修改成功");
			}
			else if (mod == 4)
			{
				printf("等日后实现奥");
				system("pause");
			}
		}
	}
	if (whether == 0)
	{
		printf("联系人不存在");
	}
	ps->person -= ps->count;//指针回归初始位置
}

int Cmp(const void* p1,const void* p2)
{
	return strcmp(((PeopleInform*)p1)->name, ((PeopleInform*)p2)->name);
}

void Sort_List(contact* ps)
{
	qsort(ps->person, ps->count, sizeof(PeopleInform), Cmp);
	printf("排序成功");
}