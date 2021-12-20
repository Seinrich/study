#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//求出直到第n项的斐波那契数列
long long* FibArr(int N)
{
	assert(N >= 0);
	int i = 0;
	int choose = 0;
	printf("网上传，斐波那契数列第一项有1的也有0的，避免争议，两种都写了\n");
	printf("选择斐波那契数列的第一项 1.1 0.0\n");
again:
	printf("请选择:>");
	scanf("%d", &choose);
	if (choose == 1)
	{
		long long* FibArr = (long long*)malloc(sizeof(long long) * (N + 1));
		FibArr[0] = 1;
		if (N < 2)
		{
			return FibArr;
		}
		FibArr[1] = 1;
		for (i = 2; i < N; i++)
		{
			FibArr[i] = FibArr[i - 1] + FibArr[i - 2];
		}
		return FibArr;
	}
	else if (choose == 0)
	{
		long long* FibArr = (long long*)malloc(sizeof(long long) * (N + 1));
		FibArr[0] = 0;
		if (N < 2)
		{
			return FibArr;
		}
		FibArr[1] = 1;
		for (i = 2; i < N; i++)
		{
			FibArr[i] = FibArr[i - 1] + FibArr[i - 2];
		}
		return FibArr;
	}
	else
	{
		printf("皮一下很开心？");
		goto again;
	}
}

int main()
{
	printf("请输入想要求至的项数(此处不考虑溢出)\n");
	printf("您想求到第几项？:>");
	int n = 0;
	scanf("%d", &n);
	long long* p = FibArr(n);
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		printf("第%d项  %-5lld\n",i, p[i-1]);
	}
}