#define _CRT_SECURE_NO_WARNINGS 1

#include "Slist.h"

int main()
{
	SlistNode* phead = NULL;
	SlistPushBack(&phead,2);
	SlistPushBack(&phead, 2);
	SlistPushBack(&phead, 2);
	SlistPushBack(&phead, 2);
	SlistPushBack(&phead, 2);
	SlistPopBack(&phead);
	SlistPopBack(&phead);
	SlistPopBack(&phead);
	SlistPopBack(&phead);
	SlistPopBack(&phead);

	PrintSlist(phead);
}
