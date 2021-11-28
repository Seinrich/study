#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i=0; i < rows; i++)
	{
		for (j=0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}

}

void PutMine(char mine[ROWS][COLS], int rows, int cols)
{
	int count = 0;
	int x = 0;
	int y = 0;
	while(count<Easy_Count)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count++;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <=row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
	printf("\n");
	}
}

//计算周围雷的个数
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return  mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x+1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

//递归空白展开
void blank(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int count = get_mine_count(mine, x, y);
	if (count == 0)
	{
		show[x][y] = ' ';
		if (x - 1 >= 1 && x <= ROW && y >= 1 && y <= COL && show[x - 1][y] == '*')
			blank(mine, show, x - 1, y);
		if (x >= 1 && x <= ROW && y - 1 >= 1 && y <= COL && show[x][y - 1] == '*')
			blank(mine, show, x, y - 1);
		if (x + 1 >= 1 && x <= ROW && y >= 1 && y <= COL && show[x + 1][y] == '*')
			blank(mine, show, x + 1, y);
		if (x >= 1 && x <= ROW && y + 1 >= 1 && y <= COL && show[x][y + 1] == '*')
			blank(mine, show, x, y + 1);
	}
	else
		show[x][y] = count + '0';
}

//判断未检查数量
int Is_Win(char show[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
				count++;
		}
	}
	return count;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col)
{
	int x = 0;
	int y = 0;
	int count = Is_Win;
	while (count!=Easy_Count)
	{
		printf("请输入排查位置:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了,雷位置如下（1为雷）\n");
				system("pause");
				DisplayBoard(mine, ROW, COL);
				system("pause");
				break;
			}
			else if (show[x][y] != '*')
				printf("此位置已查，请重新输入!");
			else
			{
				blank(mine, show, x, y);
				printf("\n");
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("此位置不正确，请重新输入!");
		}
	}
	if (count==Easy_Count)
	{
		printf("恭喜你，排雷成功");
	}
}