#pragma once

#include <stdio.h>
#include <stdlib.h>

#define SlistDataTpye int 


typedef struct SlistNode
{
	SlistDataTpye a;
	struct SlistNode* next;
}SlistNode;


//创建新结点
SlistNode* CreatSlistNode(SlistDataTpye x);

//单链表尾插
void SlistPushBack(SlistNode** pphead, SlistDataTpye x);

//单链表尾删
void SlistPopBack(SlistNode** pphead);

//单链表头插
void SlistPushFront(SlistNode** pphead, SlistDataTpye x);

//单链表头删
void SlistPopFront(SlistNode** pphead);

//单链表查找(不考虑重复数据)
SlistNode* SlistFind(SlistNode* phead,SlistDataTpye x);

//单链表间插
void SlistInserAfter(SlistNode* pos,SlistDataTpye x);

//单链表间删
void SlistEraseAfter(SlistNode* pos);

//打印单链表数据
void PrintSlist(SlistNode* phead);