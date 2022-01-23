#define _CRT_SECURE_NO_WARNINGS 1

#include"demine.h"

void Menu()
{
	printf("*************************\n");
	printf("*********扫雷游戏********\n");
	printf("***** 1.play 0.exit *****\n");
	printf("*************************\n");
	printf("请选择->");
}

void InitBoard(char board[ROWS][COLS],char set)
{
	int i, j;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}

void SetMine(char board[ROWS][COLS])
{
	int x, y;
	int count = Easy;
	while (count)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (mine[x][y] != '1')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS])
{
	int i, j;
	for (j = 0; j <= COL; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= COL; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int Get_Mine(char mine[ROWS][COLS],int x,int y)
{
	int i, j;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (mine[x+i][y+j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}

void Demine(char show[ROWS][COLS], char mine[ROWS][COLS])
{
	int x, y;
	int count = 0;
	printf("请输入要检查的坐标:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL)&&show[x][y]=='*')
		{
			if (mine[x][y] == '1')
			{
				printf("你死了,下面是雷的位置\n");
				DisplayBoard(mine);
				break;
			}
			else
			{
				int MineNum = Get_Mine(mine, x, y);
				show[x][y] = (MineNum + '0');
				count++;
				if (count == ROW * COL - Easy)
				{
					printf("赢咯\n");
					break;
				}
			}
		}
		else
		{
			printf("坐标非法，重新输入");
		}
	}

}