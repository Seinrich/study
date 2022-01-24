#define _CRT_SECURE_NO_WARNINGS 1

#include"Tic.h"

void Menu()
{
	printf("**************************\n");
	printf("****    井字棋游戏    ****\n");
	printf("**** 1.play    0.exit ****\n");
	printf("**************************\n");
	printf("请选择:>");
}

void Init(char board[ROW][COL])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Displayboard(char board[ROW][COL])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < ROW - 1)
		{
			for (j = 0; j < COL; j++)
			{
				printf("---");
				if (j < COL - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL])
{
	int x, y;
	while (1)
	{
		printf("玩家落子\n");
		printf("请输入落子坐标:>");
		scanf("%d %d", &x, &y);
		if (x > 0 && y > 0&&board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = 'x';
			break;
		}
		else
		{
			printf("落子位置错误\n");
		}
	}
	
}

void ComMove(char board[ROW][COL])
{
	printf("电脑落子\n");
	Sleep(1000);
	int x, y;
	while (1)
	{
		x = rand() % 3 + 1;
		y = rand() % 3 + 1;
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = 'o';
			break;
		}
	}
}

int JudgeFull(char board[ROW][COL])
{
	int i = 0;
	for (; i < ROW; i++)
	{
		int j = 0;
		for (; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char JudgeWin(char board[ROW][COL])
{
	int i = 0;
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][0];
		}
	}
	int j = 0;
	for (j = 0; j < COL; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[0][j];
		}
	}
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[0][2] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (1 == JudgeFull(board))
	{
		return 'N';
	}
	return 'C';
}

void Endgame(char toe)
{
	if (toe == 'x')
	{
		printf("玩家胜利\n");
	}
	else if (toe == 'o')
	{
		printf("电脑胜利\n");
	}
	else
	{
		printf("平局\n");
	}
}