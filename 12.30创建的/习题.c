#define _CRT_SECURE_NO_WARNINGS 1

#include<stdlib.h>
#include<stdio.h>

int cmp(const void* p1, const void* p2)
{
    return(*(int*)p1) - (*(int*)p2);
}

int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    int* p = malloc(sizeof(int) * numsSize);
    int i = 0;
    for (i = 0; i < numsSize; i++)
    {
        p[i] = i + 1;
    }
    int cpx = 0;
    for (i = 0; i < numsSize; i++)
    {
        cpx ^= p[i];
        cpx ^= nums[i];
    }

    qsort(nums, numsSize, sizeof(int), cmp);
    int repeat = 0;
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            repeat = nums[i];
        }
    }

    int lost = cpx ^ repeat;

    int* ReturnArr = malloc(sizeof(int) * 2);
    ReturnArr[0] = repeat;
    ReturnArr[1] = lost;
    *returnSize = 2;
    return ReturnArr;
}
