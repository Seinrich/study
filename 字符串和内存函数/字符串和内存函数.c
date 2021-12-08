#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//strcpy  ncpy
//strcmp  
//strcat  ncat

//模拟实现strcpy

char* my_strcpy(char*dest,const char*src)
{
	char* tmp = dest;
	while (*dest++ = *src++);
	return tmp;
}

//模拟实现strcmp

//1.法1

int my_strcmp(const char*p1,const char*p2)
{
	while (*p1||*p2)
	{
		if (*p1 > *p2)
			return 1;
		else if (*p1 < *p2)
			return -1;
		p1++;
		p2++;
	}
	return 0;
}

//2.法2 

int my_strcmp(const char* p1, const char* p2)
{
	while (*p1 == *p2)
	{
		if (*p1 == '\0')
			return 0;
	}
	if (*p1 > *p2)
		return 1;
	else
		return -1;
}

//模拟实现strcat

char* my_strcat(char* dest, char* src)
{
	char* tmp = dest;
	while (*dest++);
	dest--;
	while (*dest++ = *src++);
	return tmp;
}

//模拟实现strncpy

char* my_strncpy(char* dest, char* src,int n)
{
	char* tmp = dest;
	while (n)
	{
		*dest++ = *src++;
		n--;
		if (*src == '\0')
		{
			*dest = *src;
		}
	}
	while (n)
	{
		*++dest = '\0';
		n--;
	}
	return tmp;
}

//模拟实现strncat

char* my_strncat(char* dest, char* src, int n)
{
	char* tmp = dest;
	while (*dest++);
	dest--;
	while (n && *src)
	{
		*dest++ = *src++;
		n--;
	}
	*dest = *src;
	return tmp;
}

int main()
{
	char arr1[20] = "abcde\0xxxxx";
	char arr2[] = "abcde";
	my_strncat(arr1, arr2,5);
}