#define _CRT_SECURE_NO_WARNINGS 1

#include "Slist.h"

void TestBack()
{
	SlistNode* phead = NULL;
	SlistPushBack(&phead, 2);
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

void TestFront()
{
	SlistNode* phead = NULL;
	SlistPushFront(&phead, 3);
	SlistPushFront(&phead, 3);
	SlistPushFront(&phead, 3);
	SlistPushFront(&phead, 3);
	PrintSlist(phead);
	SlistPopFront(&phead);
	SlistPopFront(&phead);
	SlistPopFront(&phead);
	SlistPopFront(&phead);
	SlistPopFront(&phead);
	PrintSlist(phead);
}

void TestFind_Inster_Erase()
{
	SlistNode* phead = NULL;
	SlistPushFront(&phead, 2);
	SlistPushFront(&phead, 3);
	SlistPushFront(&phead, 5);
	SlistPushFront(&phead, 7);
	SlistNode* pNode = SlistFind(phead, 8);
	if (pNode != NULL)
	{
		printf("%d", pNode->a);
	}
	SlistInserAfter(SlistFind(phead, 3), 6);
	PrintSlist(phead);
	printf("\n");
	SlistEraseAfter(phead);

	PrintSlist(phead);
}

int main()
{
	//TestBack();
	//TestFront();
	TestFind_Inster_Erase();
}
