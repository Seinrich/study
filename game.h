#define ROW 9
#define COL 9
#define ROWS ROW+2//11行便于计算雷数
#define COLS COL+2//11列便于计算雷数

#define Easy_Count 10//简单模式雷的数量

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);
void PutMine(char mine[ROWS][COLS], int rows,int cols);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
int get_mine_count(char mine[ROWS][COLS], int x, int y);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);