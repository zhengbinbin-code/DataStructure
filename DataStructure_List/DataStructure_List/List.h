#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

//创建返回链表的头结点
ListNode* ListCreate();

//双向链表销毁
void ListDestory(ListNode* phead);

//双向链表打印
void ListPrint(ListNode* phead);

//双向链表尾插
void ListPushBack(ListNode* phead, LTDataType x);

//双向链表尾删
void ListPushBack(ListNode* phead);

//双向链表头插
void ListPushFront(ListNode* phead, LTDataType x);

//双向链表头删
void ListPopFront(ListNode* phead);





ListNode* ListFind(ListNode* phead, LTDataType x);
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 删除pos位置的节点
void ListErase(ListNode* pos);
void ListRemove(ListNode* phead, LTDataType x);
