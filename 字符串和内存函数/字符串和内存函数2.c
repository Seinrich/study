#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

//Ä£Äâstrstr

char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	if (!*p2)
		return (char*)p1;
	char* s1 = (char*)p1;
	char* s2 = (char*)p2;
	char* cur = (char*)p1;
	while (*s1)
	{
		char* s1 = cur;
		s2 = (char*)p2;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (!*s2)
			return cur;
		cur++;
	}
	return NULL;
}

int main()
{
	char a1[] = "abcde";
	char a2[] = "bc";
	printf("%s\n", my_strstr(a1, a2));
}