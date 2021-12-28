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


//打印单链表数据
void PrintSlist(SlistNode* phead);