#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode 
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

//声明一个指针,指向SList
SListNode* pList;

//链表初始化
void SListInit(SListNode** pList);

//链表销毁
void SListDestory(SListNode** pList);

//打印函数
void SListPrint(SListNode* pList);

//创建一个节点
SListNode* BuySListNode(SLTDataType x);

//尾插
void SListPushBack(SListNode** pList,SLTDataType x);

//头插
void SListPushFront(SListNode** pList, SLTDataType x);

//尾删
void SListPopBack(SListNode** pList);

//头删
void SListPopFront(SListNode** pList);

//指定值查找
SListNode* SListFind(SListNode* pList, SLTDataType x);

//指定位置后插
void SListInsertAfter(SListNode* pos, SLTDataType x);

//指定位置后删
void SListEraseAfter(SListNode* pos);

//统计链表中的元素个数
int GetListLength(SListNode* first);




//删除第一个遇到的指定值x
void SListRemove(SListNode** pList, SLTDataType x);

//删除遇到的所有指定值x
void SListRemoveAll(SListNode** pList, SLTDataType x);



  
