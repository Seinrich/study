#pragma once

#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

char board[ROW][COL];

void Menu();

void Init(char board[ROW][COL]);

void Displayboard(char board[ROW][COL]);

void PlayerMove(char board[ROW][COL]);

void ComMove(char board[ROW][COL]);

int JudgeFull(char board[ROW][COL]);

char JudgeWin(char board[ROW][COL]);

void Endgame(char toe);

