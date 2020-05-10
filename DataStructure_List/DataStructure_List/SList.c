#include"SList.h"

//链表初始化
void SListInit(SListNode** pList)
{
	pList = NULL;
}

//链表销毁
void SListDestory(SListNode* *pList)
{
	SListNode* next;
	for (SListNode* cur = *pList; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	*pList = NULL;
}

//打印函数
void SListPrint(SListNode* pList)
{
	SListNode* cur = pList;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//创建一个节点
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//尾插
void SListPushBack(SListNode* *ppList, SLTDataType x)
{
	SListNode* newNode = BuySListNode(x);
	if (*ppList == NULL)
	{
		*ppList = newNode;
	}
	else
	{
		SListNode* tail = *ppList;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}

//头插
void SListPushFront(SListNode* *ppList, SLTDataType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = *ppList;
	*ppList = newNode;
}

//尾删
void SListPopBack(SListNode* *ppList)
{
	//链表为空
	if (*ppList == NULL)
	{
		return;
	}
	//链表只有一个节点
	else if ((*ppList)->next == NULL)
	{
		free(*ppList);
		*ppList = NULL;
	}
	//链表有多个节点
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *ppList;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		if (prev != NULL)
		{
			prev->next = NULL;
		}
	}
}

//头删
void SListPopFront(SListNode* *pList)
{
	assert(*pList);
	SListNode* next = (*pList)->next;
	free(*pList); 
	*pList = next;
}

//指定值查找
SListNode* SListFind(SListNode* pList, SLTDataType x)
{
	SListNode* cur = pList;
	while (cur)
	{
		if (cur->data == x)
		{
			//printf("找到了%d\n",cur->data);//测试
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	//printf("没找到\n");//测试
	return NULL;
}

//指定位置之后插
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

//指定位置之后删
void SListEraseAfter(SListNode* pos)
{
	SListNode* next = pos->next;
	if (next != NULL)
	{
		pos->next = next->next;
		free(next);
	}
}

//统计链表中的元素个数
int GetListLength(SListNode* pList)
{
	SListNode* cur = pList;
	int count = 0;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	//printf("单链表共有%d个节点", count);//测试代码
	return count;
}

////删除第一个遇到的指定值x
//void SListRemove(SListNode** pList, SLTDataType x)
//{
//	assert(*pList);
//	SListNode* cur = pList;
//	if (cur->data == x)
//	{
//		SListNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	else
//	{
//		SListNode* prev = NULL;
//		while (cur && cur->data != NULL)
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//		prev->next = cur->next;
//		free(cur);
//		cur = prev->next;
//	}
//}

////删除遇到的所有指定值x
//void SListRemoveAll(SListNode** pList, SLTDataType x)
//{
//	SListNode* cur = pList;
//	SListNode* prev = NULL;
//	while (cur != NULL)
//	{
//		if (cur->data == x)
//		{
//			SListNode* next = cur->next;
//			free(cur);
//			if (cur == pList)
//			{
//				pList = next;
//			}
//			else
//			{
//				prev->next = next;
//			}
//			cur = next;
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//}





