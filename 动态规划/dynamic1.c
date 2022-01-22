#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//62.一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

//问总共有多少条不同的路径？

int uniquePaths(int m, int n)
{
    int(*p)[n] = malloc(sizeof(int) * (m) * (n));
    int row = m, col = n;
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (i == 0 || j == 0)
            {
                p[i][j] = 1;
            }
            else
            {
                p[i][j] = p[i - 1][j] + p[i][j - 1];
            }
        }
    }
    int re = p[i - 1][j - 1];
    free(p);
    return re;
}


//103.给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回  - 1。

//你可以认为每种硬币的数量是无限的

int min(int x, int y)
{
    return x < y ? x : y;
}

int coinChange(int* coins, int coinsSize, int amount)
{
    int* p = malloc(sizeof(int) * (amount + 1));
    int i, j;
    p[0] = 0;
    for (i = 1; i <= amount; i++)
    {
        p[i] = amount + 1;
        for (j = 0; j < coinsSize; j++)
        {
            if (i - coins[j] >= 0)
            {
                p[i] = min(p[i - coins[j]] + 1, p[i]);
            }
        }
    }
    if (p[amount] == (amount + 1))
    {
        return -1;
    }
    else
    {
        return p[amount];
    }
}

//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

//数组中的每个元素代表你在该位置可以跳跃的最大长度。

//判断你是否能够到达最后一个下标。

bool canJump(int* nums, int numsSize)
{
    int* p = malloc(sizeof(int) * numsSize);
    p[0] = 1;
    int i;
    for (i = 1; i < numsSize; i++)
    {
        p[i] = 0;
        int j = 0;
        for (j = 0; j < i; j++)
        {
            if (p[j] && nums[j] + j >= i)
            {
                p[i] = 1;
                break;
            }
        }
    }
    return p[i - 1];
}