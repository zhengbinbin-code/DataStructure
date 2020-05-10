#include"SList.h"

//�����ʼ��
void SListInit(SListNode** pList)
{
	pList = NULL;
}

//��������
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

//��ӡ����
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

//����һ���ڵ�
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//β��
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

//ͷ��
void SListPushFront(SListNode* *ppList, SLTDataType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = *ppList;
	*ppList = newNode;
}

//βɾ
void SListPopBack(SListNode* *ppList)
{
	//����Ϊ��
	if (*ppList == NULL)
	{
		return;
	}
	//����ֻ��һ���ڵ�
	else if ((*ppList)->next == NULL)
	{
		free(*ppList);
		*ppList = NULL;
	}
	//�����ж���ڵ�
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

//ͷɾ
void SListPopFront(SListNode* *pList)
{
	assert(*pList);
	SListNode* next = (*pList)->next;
	free(*pList); 
	*pList = next;
}

//ָ��ֵ����
SListNode* SListFind(SListNode* pList, SLTDataType x)
{
	SListNode* cur = pList;
	while (cur)
	{
		if (cur->data == x)
		{
			//printf("�ҵ���%d\n",cur->data);//����
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	//printf("û�ҵ�\n");//����
	return NULL;
}

//ָ��λ��֮���
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}

//ָ��λ��֮��ɾ
void SListEraseAfter(SListNode* pos)
{
	SListNode* next = pos->next;
	if (next != NULL)
	{
		pos->next = next->next;
		free(next);
	}
}

//ͳ�������е�Ԫ�ظ���
int GetListLength(SListNode* pList)
{
	SListNode* cur = pList;
	int count = 0;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	//printf("��������%d���ڵ�", count);//���Դ���
	return count;
}

////ɾ����һ��������ָ��ֵx
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

////ɾ������������ָ��ֵx
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





