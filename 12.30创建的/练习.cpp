#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//删除重复字符(若字符串中全部是同一字符则保留一个字符，字符串不含空格)

void DelRepeat(char* p)
{
	int i = 0;
	int n = strlen(p);
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = i + 1; j < n; j++)
		{
			if (p[i] == p[j])
			{
				p[j] = ' ';
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (p[i] == ' ')
		{
			int j = 0;
			int a = i;
			for (j = a + 1; j < n+1; j++)//拿/0
			{
				p[a] = p[j];
				a++;
			}
			i -= 1;//针对连续空格的调整，使之必定被替换
		}
	}
}

//删除重复字符(重复字符全删，字符串不含空格)

void DelRepeat1(char* p)
{
	int i = 0;
	int n = strlen(p);
	int count = 0;//记录有多少个i被记录
	int whether = 0;
	int j = 1;
	int* pi = (int*)malloc(sizeof(int));
	for (i = 0; i < n; i++)
	{
		int j = 0;
		whether = 0;
		for (j = i + 1; j < n; j++)
		{
			if (p[i] == p[j])
			{
				p[j] = ' ';
				whether++;
				if (whether == 1)
				{//记录此时的i
					count++;
					int* ptr = (int*)realloc(pi, sizeof(int) * count);
					if (ptr)
					{
						pi = ptr;
						pi[count - 1] = i;
					}
				}
			}
		}
	}
	for (i = count; i; i--)
	{
		p[pi[count-j]] = ' ';
		j++;
	}
	for (i = 0; i < n; i++)
	{
		if (p[i] == ' ')
		{
			int j = 0;
			int a = i;
			for (j = a + 1; j < n + 1; j++)//拿/0
			{
				p[a] = p[j];
				a++;
			}
			i -= 1;//针对连续空格的调整，使之必定被替换
		}
	}
}

int cmp_int(const void* p1, const void* p2)
{
	return *((int*)p1) - *((int*)p2);
}

//切割字符，但是还不完善

void strtok1(char*str,char*tok)
{
	int i = 0;//循环变量,控制tok中的字符
	int lenstr = strlen(str);
	int lentok = strlen(tok);
	int count = 0;
	int j = 0;//循环变量，控制str中的字符
	int* pi = (int*)malloc(sizeof(int));
	for (i = 0; i < lentok; i++)
	{
		for (j = 0; j < lenstr; j++)
		{
			if (tok[i] == str[j])
			{
				count++;//count是pi数组中的元素个数
				str[j] = '\0';
				int* ptr = (int*)realloc(pi,sizeof(int) * count);
				if (ptr)
				{
					pi = ptr;
					pi[count - 1] = j;//要额外+1才能指向\0后面
				}
			}
		}
	}
	char* pt = str;//作为str的副本，不损伤str
	printf("%s\n", pt);
	if (count > 1)
	{
		qsort(pi, count, sizeof(int), cmp_int);
	}
	for (i = 0; i <= count - 1; i++)
	{
		pt = str;
		pt += pi[i] + 1;
		printf("%s\n", pt);
	}
}

int main()
{
	char str[81] = "";
	gets_s(str);
	//DelRepeat1(ch)
	char tok[81] = "";
	gets_s(tok);
	strtok1(str, tok);
}