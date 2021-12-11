#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Arr()
{
	int n = 0;
	scanf("%d", &n);
	int i = 1;
	int count = 0;
	int* p = (int*)malloc(sizeof(int));
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			count++;
			int* ptr = (int*)realloc(p, count * sizeof(int));
			if (ptr != NULL)
			{
				p = ptr;
			}
			p[count - 1] = i;
		}
	}
	printf("%d的所有因数为:", n);
	for (int j = 0; j < count; j++)
	{
		printf("%d ", p[j]);
	}
	printf("\n");
}

int main()
{
	Arr();
}