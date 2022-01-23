#pragma once

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Easy 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char show[ROWS][COLS];
char mine[ROWS][COLS];

void Menu();

void InitBoard(char board[ROWS][COLS],char set);

void SetMine(char board[ROWS][COLS]);

void DisplayBoard(char board[ROWS][COLS]);

void Demine(char show[ROWS][COLS],char mine[ROWS][COLS]);

