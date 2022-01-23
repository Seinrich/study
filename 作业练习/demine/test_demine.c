#define _CRT_SECURE_NO_WARNINGS 1

#include"demine.h"

void test()
{
	int input = 1;
	do
	{
		Menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			InitBoard(show, '*');
			InitBoard(mine, '0');
			SetMine(mine);
			DisplayBoard(show);
			Demine(show, mine);
			break;
		case 0:
			break;
		default:
			printf("ÖØĞÂÑ¡Ôñ:>");
			break;
		}
	} while (input);

}

int main()
{
	srand((unsigned int)time(NULL));
	test();
}