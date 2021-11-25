#define ROW 3
#define COL 3

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

void Initboard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void Player1Move(char board[ROW][COL], int row, int col);
void Player2Move(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char Is_Win(char board[ROW][COL], int row, int col);
int Is_Full(char board[ROW][COL], int row, int col);
