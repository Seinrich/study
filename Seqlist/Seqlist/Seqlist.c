#define _CRT_SECURE_NO_WARNINGS 1
#include"Seqlist.h"

void SeqInit(seqlist* ps)
{
	ps->p = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(seqlist* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->p[i]);
	}
}

void CheckCapacity(seqlist* ps)
{
	if (ps->size >= ps->capacity)
	{
		SeqDateType* newp = (SeqDateType*)realloc(ps->p, (ps->capacity + 1) * 2 * sizeof(SeqDateType));
		if (newp == NULL)
		{
			printf("ÄÚ´æ²»×ã\n");
			return;
		}
		ps->p = newp;
		ps->capacity = (ps->capacity + 1) * 2;
	}
}

void SeqListInsert(seqlist* ps, int pos, SeqDateType x)
{
	if (pos > ps->size)
		return;
	CheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->p[i] = ps->p[i-1];
	}
	ps->p[pos] = x;
	ps->size++;
}

void SeqListPushBack(seqlist* ps, SeqDateType x)
{
	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(seqlist* ps, SeqDateType x)
{
	SeqListInsert(ps, 0, x);
}

void SeqListErase(seqlist* ps, int pos)
{
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->p[i] = ps->p[i + 1];
	}
	ps->size--;
}

void SeqListPopFront(seqlist* ps)
{
	SeqListErase(ps, 0);
}

void SeqListPopBack(seqlist* ps)
{
	SeqListErase(ps, ps->size - 1);
}

int SeqListFind(seqlist* ps, SeqDateType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->p[i] == x)
		{
			return i;
		}
	}
	return -1;
}
