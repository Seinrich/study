#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

/*if (money % 2 != 0)
	{
		while ((empty))
		{
			if ((empty % 2 == 0) && empty != 0)
			{
				empty = (empty + left) / 2;
				total += empty;
				left = 0;
			}
			else
			{
				total = total + (empty + left) / 2;
				empty = empty / 2;
				left = 1;
			}
		}
	}
	else
	{
		while ((empty + left))
		{
			if ((empty % 2 == 0) && empty != 0)
			{
				empty = (empty + left) / 2;
				total += empty;
				left = 0;
			}
			else if (empty % 2 == 1)
			{
				total = total + (empty + left) / 2;
				empty = empty / 2;
				left = 1;
			}
			else
			{
				total += 1;
				left = 0;
			}
		}
	}*/
//int main()
//{
//	int money = 20;
//	scanf("%d", &money);
//	int total = money;
//	int empty = money;
//	//价值交换角度
//	// total = 2*money - 1;
//	
//	//
//	/*while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty % 2;
//	}*/
//	/*int left = 0;
//	int whether = 0;
//	int count = 0;*/
//	/*while (empty)
//	{
//		if (empty % 2 == 0)
//		{
//			empty = (empty + left) / 2;
//			total += empty;
//			left = 0;
//			whether = 0;
//		}
//		else if (empty%2==1)
//		{
//			total = total + empty / 2;
//			empty = empty / 2;
//			left = 1;
//			whether = 1;
//			count++;
//		}
//	}
//	if (whether == 1&&count>1)
//	{
//		total += 1;
//	}
//	printf("%d", total);*/
//	printf("%d", total);
//}

void verse(char* p, int n)
{
	int i = 0;
	int sz = strlen(p);
	for (i = 0; i < n; i++)
	{
		char tmp = p[0];
		int j = 0;
		for (j = 1; j < sz; j++)
			p[j-1] = p[j];
		p[sz - 1] = tmp;
	}
}

int main()
{
	char arr[] = "abcd";
	int n = 0;
	scanf("%d", &n);
	verse(arr,n);
	printf("%s", arr);
}