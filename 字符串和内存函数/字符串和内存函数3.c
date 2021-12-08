#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//Ä£ÄâÊµÏÖmemmove

void* memmove(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	if (dest < src)
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			++(char*)dest;
			++(char*)src;
		}
		return ret;
	}
	else
	{
		while (num--)
		{
			char* des_r = (char*)dest+num;
			char* src_r = (char*)src+num;
			*(char*)des_r = *(char*)src_r;
			//--(char*)des_r;
			//--(char*)src_r;
		}
		return ret;
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	memmove(arr+2, arr, 20);
}