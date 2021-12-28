#define _CRT_SECURE_NO_WARNINGS 1

#include "Slist.h"

SlistNode* CreatSlistNode(SlistDataTpye x)
{
	SlistNode* NewNode = (SlistNode*)malloc(sizeof(SlistNode));
	if (NewNode == NULL)
	{
		exit(-1);
	}

	NewNode->a = x;
	NewNode->next = NULL;

	return NewNode;
}

void SlistPushBack(SlistNode** pphead, SlistDataTpye x)
{
	SlistNode* NewNode = CreatSlistNode(x);
	if (*pphead == NULL)
	{
		*pphead = NewNode;
	}
	else
	{
		SlistNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}

		ptail->next = NewNode;
	}
}

void SlistPopBack(SlistNode** pphead)
{
	//使用时，可能链表是空链表，此时什么也不做
	if (*pphead == NULL)
	{
		return;
	}
	else if ((*pphead)->next == NULL)
	{
		free((*pphead)->next);
		(*pphead) = NULL;
	}
	else
	{
		SlistNode* prev = NULL;
		SlistNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void PrintSlist(SlistNode* phead)
{
	if (phead == NULL)
	{
		return;
	}
	else
	{
		SlistNode* tail = phead;
		while (tail != NULL)
		{
			printf("%d->", tail->a);
			tail = tail->next;
		}
	}
}