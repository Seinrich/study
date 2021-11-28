#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//�˵�
void menu()
{
	printf("***************************\n");
	printf("******    1.play     ******\n");
	printf("******    0.exit     ******\n");
	printf("***************************\n");
}

//��Ϸ��
void game()
{
	//�������̣�����
	char mine[ROWS][COLS] = {0};
	//�����û�����
	char show[ROWS][COLS] = {0};
	//��ʼ������
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//�������
	PutMine(mine, ROWS, COLS);
	//������Ϊ���Ż���Ϸ����
	printf("\n");
	//չʾ���̣��û��̣�
	DisplayBoard(show, ROW, COL);
	//ִ����Ϸ
	FindMine(mine, show, ROW, COL);
}

//������
void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do 
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
		default:
			break;
		}
	} while (input);
}

int main()
{
	test();
}