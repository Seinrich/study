#define _CRT_SECURE_NO_WARNINGS 1

#include"address list.h"

int main()
{
	menu();
	int choose = 0;
	scanf("%d", &choose);
	enum address_list;
	switch (choose)
	{
	case creat:
		Creat_New();
		break;
	case search:
		break;
	case modify:
		break;
	case sort:
		break;
	case special:
		break;
	default:
		break;
	}
}