#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#include<malloc.h>

//无法处理大数据

//int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
//{
//    if(k==0)
//    {
//        *returnSize = numSize;
//        return num;
//    }
//    int i = 0;
//    int tmp = numSize;
//    unsigned long long ret = 0;
//    unsigned long long sum = 0;
//    int count = 0;//统计和数有几位
//    for(i=0;i<numSize;i++)
//    {
//        ret = (unsigned long long)(num[i])*pow(10,tmp-1);
//        sum += ret;
//        tmp--;
//    }
//    unsigned long long Sum_n_k = sum + k;
//    unsigned long long copy = Sum_n_k;
//    while(copy)
//    {
//        copy /= 10;
//        count++;
//    }
//    int* pReturnArr = (int*)malloc(sizeof(int)*count);
//    i = count-1;
//    for(;Sum_n_k;)
//    {
//        pReturnArr[i] = Sum_n_k % 10;
//        Sum_n_k /= 10;
//        i--;
//    }
//    *returnSize = count;
//    return pReturnArr;
//}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
//{
//    int kcopy = k;
//    int kSize = 0;
//    int ret = 0;
//    while (kcopy)
//    {
//        kSize++;
//        kcopy /= 10;
//    }
//    int len = kSize > numSize ? kSize : numSize;// k与num谁的位数更多
//    int i = numSize - 1;
//    int carry = 0;//是否进位
//    int* returnArr = (int*)malloc(sizeof(int) * (len + 1));//即使进位，也最多是比最长数位多一位
//    int m = len;//m是len的副本，用来对returnArr数组放置元素时定位下标，从最后的位置开始放
//    int lencopy = len;//lencopy是len的副本，用来返回returnSize的指向值
//    while (len)
//    {
//        //针对数组元素个数小于k的位数
//        int a = 0;
//        if (i >= 0)
//        {
//            a = num[i];
//            i--;
//        }
//        ret = a + k % 10 + carry;
//        k /= 10;
//        if (ret > 9)
//        {
//            ret -= 10;
//            carry = 1;
//        }
//        else
//        {
//            carry = 0;
//        }
//        returnArr[m] = ret;
//        len--;
//        m--;
//    }
//    if (carry == 1)
//    {
//        returnArr[m] = 1;
//        *returnSize = lencopy + 1;
//        return returnArr;
//    }
//    else
//    {
//        //由于额外多开辟了一个整形空间，最高位相加不进位时，需要返回returnArr+1，跳过第一个元素
//        *returnSize = lencopy;
//        return returnArr + 1;
//    }
//}

//35. 搜索插入位置
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

//请必须使用时间复杂度为 O(log n) 的算法。

//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/search-insert-position
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            break;
        }
    }
    if (nums[mid] >= target)
    {
        return mid;
    }
    else
    {
        return mid + 1;
    }
}

//int main()
//{
//    int arr[] = { 3,8,0,3,0,2,7,0,7,6,4,9,9,1,7,6,6,1,6 };
//    int k = 670;
//    int resize = 0;
//    int* p = &resize;
//    addToArrayForm(arr, sizeof(arr) / sizeof(arr[0]), k, p);
//}