#define _CRT_SECURE_NO_WARNINGS 1

#include"address list.h"

int main()
{
	contact Con_Peo;
	Init(&Con_Peo);
	int choose = 1;
	menu();
	while(choose)
	{
		printf("1.创建联系人  2.展示列表  3.查找联系人  4.删改联系人  5.排序联系人\n");
		printf("请选择:>");
		scanf("%d", &choose);
		switch (choose)
		{
		case creat:
			Creat_New(&Con_Peo);
			break;
		case show:
			Show(&Con_Peo);
			break;
		case search:
			Search(&Con_Peo);
			break;
		case modify:
			break;
		case sort:
			break;
		case special:
			break;
		default:
			printf("选择错误，重新选择");
			system("cls");
			break;
		}
	}
	
}