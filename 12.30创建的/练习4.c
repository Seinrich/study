#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define false -1
#define bool int
#define true 1

//移除数组中指定元素，不开辟额外空间

//int removeElement(int* nums, int numsSize, int val)
//{
//    int i = 0;
//    int count = 0;
//    int newsize = numsSize;
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == val)
//        {
//            count++;
//        }
//    }
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] == val)
//        {
//            int start = i;
//            for (; start < numsSize - 1; start++)
//            {
//                if (nums[start + 1] != nums[start]||nums[start+1]!=val)
//                {
//                    nums[start] = nums[start + 1];
//                }
//                else
//                {
//                    int j = 0;
//                    for (j = 1; j < numsSize - 1 - start; j++)
//                    {
//                        if (*(nums + start + j) != *(nums + start + j + 1))
//                        {
//                            nums[start] = nums[start + j + 1];
//                            int n = start + j + 1;
//                            for (n = start + j + 1; n < numsSize - 1; n++)
//                            {
//                                nums[n] = nums[n + 1];
//                            }
//                            if (nums[n] == val)
//                            {
//                                numsSize -= 1;
//                            }
//                            
//                            break;
//                        }
//                    }
//                }
//            }
//            if (nums[start] == val)
//            {
//                numsSize -= 1;
//            }
//        }
//    }
//    return newsize-count;
//}

//最长公共前缀

//char* longestCommonPrefix(const char** strs, int strsSize)
//{
//    if (strsSize < 2)
//    {
//        return strs[strsSize-1];
//    }
//    int i = 0;
//    int j = 0;
//    int minlen = strlen(strs[0]);
//    int conlen = 0;
//    char* conchar = (char*)malloc(sizeof(char) * (strsSize+1));
//    for (i = 0; i < strsSize - 1; i++)
//    {
//        if (strlen(strs[i]) > strlen(strs[i + 1]) && minlen > strlen(strs[i + 1]))
//        {
//            minlen = strlen(strs[i + 1]);
//        }
//        else if (strlen(strs[i]) < strlen(strs[i + 1]) && minlen > strlen(strs[i]))
//        {
//            minlen = strlen(strs[i]);
//        }
//    }
//    for (j = 0; j < minlen; j++)
//    {
//        for (i = 0; i < strsSize - 1; i++)
//        {
//            if ((*(*(strs + i) + j)) != (*(*(strs + i + 1) + j)))
//            {
//                break;
//            }
//        }
//        if (i == strsSize - 1)
//        {
//            conlen++;
//            conchar[conlen - 1] = strs[i][j];
//        }
//        else
//        {
//            break;
//        }
//    }
//    conchar[conlen] = '\0';
//    return conchar;
//}

//

bool isValid(char* s)
{
    if (strlen(s) < 2)
    {
        return false;
    }

    int i = 0;
    int j = 0;

    int left1 = 0;
    int left2 = 0;
    int left3 = 0;
    int right1 = 0;
    int right2 = 0;
    int right3 = 0;

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(')
        {
            if (s[i + 1] == '}' || s[i + 1] == ']')
            {
                return false;
            }
            for (j = i + 1; j < strlen(s) - i; j++)
            {
                if (s[j] == ')')
                {
                    break;
                }
            }
            if (s[j] != ')'|| ((j - i) % 2 == 0))
            {
                return false;
            }
            left1++;
        }
        if (s[i] == '[')
        {
            if (s[i + 1] == ')' || s[i + 1] == '}')
            {
                return false;
            }
            for (j = i + 1; j < strlen(s) - i; j++)
            {
                if (s[j] == ']')
                {
                    break;
                }
            }
            if (s[j] != ']' ||  ((j - i) % 2 == 0))
            {
                return false;
            }
            left2++;
        }
        if (s[i] == '{')
        {
            if (s[i + 1] == ')' || s[i + 1] == ']')
            {
                return false;
            }
            for (j = i + 1; j < strlen(s) - i; j++)
            {
                if (s[j] == '}')
                {
                    break;
                }
            }
            if (s[j] != '}' || ((j - i) % 2 == 0))
            {
                return false;
            }
            left3++;
        }
        if (s[i] == ')')
        {
            if (i != 0)
            {
                if (s[i - 1] == '{' || s[i - 1] == '[')
                {
                    return false;
                }
            }
            right1++;
        }
        if (s[i] == ']')
        {
            if (i != 0)
            {
                if (s[i - 1] == '{' || s[i - 1] == '(')
                {
                    return false;
                }
            }
            right2++;
        }
        if (s[i] == '}')
        {
            if (i != 0)
            {
                if (s[i - 1] == '(' || (s[i - 1] == '['))
                {
                    return false;
                }
            }
            right3++;
        }
    }
    if (left1 == right1 && left2 == right2 && left3 == right3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char strs[] = { "(([]){})" };
    int i = isValid(strs);
    //longestCommonPrefix(strs,1);
    //int arr[] = { 3,2,2,3 };
    //int sz = sizeof(arr) / sizeof(arr[0]);
    //int i  =  removeElement(arr, sz, 3);
    //return 0;
}