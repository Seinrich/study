#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>


//代码嵌套可能比较多，耐心看，有时间我再看看能不能简化吧
int is_prime(int x)
{
	int i = 0;
	for (i = 2; i < sqrt(x); i++)
	{
		if (x % i == 0)
			break;
	}
	if (x % i != 0)
		return 1;
	return 0;
}

void Elements_Is_Prime(int n)
{
	int could = 1;//用于得知最终结果
	if (n < 5)//这些数一定不可以，我懒得放下面去了
	{
		printf("不行，不可以哦！");
		return;
	}
	//试除法最优算法无法算出2和3是素数（不能直接）
	int ele1, ele2;
	for (ele1 = 2; ele1 < n - 1; ele1++)
	{
		ele2 = n - ele1;//让ele2最小从2开始
		if (ele1 < ele2)//防重复
		{
			if (ele1 == 2)
			{
				ele2 = 3;//ele2不需单独列出2
				if ((ele2 + ele1) == n)
				{
					printf("可表示为素数 %d %d 的和", ele1, ele2);
					could++;
				}
				else
				{
					ele2 = n - ele1;
					int whether = is_prime(ele2);
					if (whether == 1)
					{
						printf("可表示为素数 %d %d 的和", ele1, ele2);
						could++;
					}
				}
			}
			else if (ele1 == 3)
			{
				int whether = is_prime(ele2);
				if (whether == 1)
				{
					printf("可表示为素数 %d %d 的和", ele1, ele2);
					could++;
				}
			}
			else//ele1>3，此时可用试除法最优算法
			{
				int whether1 = is_prime(ele1);
				int whether2 = is_prime(ele2);
				if ((whether1 + whether2) == 2)
				{
					printf("可表示为素数 %d %d 的和", ele1, ele2);
					could++;
				}
			}

		}
	}
	if (could == 1)
		printf("不行，不可以哦！");
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	Elements_Is_Prime(n);
}