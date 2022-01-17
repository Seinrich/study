#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//猜数字

void MenuStart()
{
	printf("猜数字游戏\n");
	printf("1.开始 0.退出\n");
	printf("请选择:>");
}

int MenuEnd()
{
	int choose = 0;
	printf("要再玩吗？");
	printf("1.继续 0.退出\n");
	printf("请选择:>");
	scanf("%d", &choose);
	return choose;
}

void game()
{
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	while (1)
	{
		int guess = 0;
		printf("数字为1到100之间\n");
		printf("请猜数:>");
		scanf("%d", &guess);
		if (guess > num)
		{
			printf("猜大了\n");
		}
		else if (guess < num)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜,猜对了!\n\n");
			system("pause");
			break;
		}
	}
}

int main()
{
	int choose = 1;
	MenuStart();
	scanf("%d", &choose);
	while (choose)
	{
		game();
		choose = MenuEnd();
	}
}

//int main()
//{
//	int arr[] = { 2,3,4,5,14,34,523,754,74565,332221};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int mid = 0;
//	int k = 0;
//	int input = 1;
//	while (1)
//	{
//		int left = 0;
//		int right = sz - 1;
//		printf("1.开始查找 0.结束:>");
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			break;
//		}
//		printf("查找数字：");
//		scanf("%d", &k);
//		while (left <= right)
//		{
//			mid = left + (right-left) / 2;
//			if (arr[mid] > k)
//			{
//				right = mid - 1;
//			}
//			else if (arr[mid] < k)
//			{
//				left = mid + 1;
//			}
//			else
//			{
//				printf("找到了，下标为：%d\n", mid);
//				break;
//			}
//		}
//		if (left > right)
//		{
//			printf("找不到\n");
//		}
//	}
//}

//int Fac(int i)
//{
//	int ret = 1;
//	for (int n = 1; n <= i; n++)
//	{
//		ret *= n;
//	}
//	return ret;
//}

//int main()
//{
//	int sum = 0;
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 1; i <= n; i++)
//	{
//		sum += fac(i);
//	}
//	printf("%d", sum);
//}

//int main()
//{
//    int i = 0;
//    for (i = 0; i < 2; i++)
//    {
//        int j = 0;
//        for (j = 0; j < 5; j++)
//        {
//            printf(" ");
//        }
//        printf("**");
//        for (j = 0; j < 5; j++)
//        {
//            printf(" ");
//        }
//        printf("\n");
//    }
//    for (i = 0; i < 2; i++)
//    {
//        int j = 0;
//        for (j = 0; j < 12; j++)
//        {
//            printf("*");
//        }
//        printf("\n");
//    }
//    for (i = 0; i < 2; i++)
//    {
//        int j = 0;
//        for (j = 0; j < 4; j++)
//        {
//            printf(" ");
//        }
//        printf("*  *");
//        for (j = 0; j < 4; j++)
//        {
//            printf(" ");
//        }
//        printf("\n");
//    }
//}

//int main()
//{
//	char ch;
//	ch = getchar();
//	printf("%c", ch);
//}