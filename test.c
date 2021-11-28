#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//菜单
void menu()
{
	printf("***************************\n");
	printf("******    1.play     ******\n");
	printf("******    0.exit     ******\n");
	printf("***************************\n");
}

//游戏体
void game()
{
	//创建棋盘，雷盘
	char mine[ROWS][COLS] = {0};
	//创建用户棋盘
	char show[ROWS][COLS] = {0};
	//初始化棋盘
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//随机放雷
	PutMine(mine, ROWS, COLS);
	//换行是为了优化游戏体验
	printf("\n");
	//展示棋盘（用户盘）
	DisplayBoard(show, ROW, COL);
	//执行游戏
	FindMine(mine, show, ROW, COL);
}

//测试体
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do 
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
		default:
			break;
		}
	} while (input);
}

int main()
{
	test();
}