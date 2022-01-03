#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

//28 实现 strStr() 函数。

//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  - 1

int strStr(char* haystack, char* needle)
{
    if (!*needle)
    {
        return 0;
    }
    char* phaystack = haystack;
    char* pneedle = needle;
    char* cur = haystack;
    int pos = 0;
    while (phaystack)
    {
        phaystack = cur;//父串指针一次移动一个字符
        pneedle = needle;//子串指针回归初始位置
        while (*phaystack && *pneedle && *phaystack == *pneedle)
        {
            phaystack++;
            pneedle++;
        }
        if (!*pneedle)
        {
            return pos;
        }
        cur++;
        pos++;
    }
    return -1;
}

//模拟strstr

//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 && p2);
//	if (!*p2)
//		return (char*)p1;
//	char* s1 = (char*)p1;
//	char* s2 = (char*)p2;
//	char* cur = (char*)p1;
//	while (*s1)
//	{
//		char* s1 = cur;
//		s2 = (char*)p2;
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (!*s2)
//			return cur;
//		cur++;
//	}
//	return NULL;
//}

int main()
{
	char a1[] = "hello";
	char a2[] = "lo";
	printf("%d\n", strStr(a1, a2));
}