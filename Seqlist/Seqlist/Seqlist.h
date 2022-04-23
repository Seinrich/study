#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SeqDateType;

typedef struct Seqlist
{
	SeqDateType* p;
	int size;
	size_t capacity;

}seqlist;

void SeqInit(seqlist* ps);
void SeqDestory(seqlist* ps);

// 对数据的管理:增删查改 
void SeqListPrint(seqlist* ps);
void SeqListPushBack(seqlist* ps, SeqDateType x);
void SeqListPushFront(seqlist* ps, SeqDateType x);
void SeqListPopFront(seqlist* ps);
void SeqListPopBack(seqlist* ps);

// 顺序表查找
int SeqListFind(seqlist* ps, SeqDateType x);
// 顺序表在pos位置插入x
void SeqListInsert(seqlist* ps, int pos, SeqDateType x);
// 顺序表删除pos位置的值
void SeqListErase(seqlist* ps, int pos);
