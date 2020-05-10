#include"List.h"

//�������������ͷ���
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//˫����������
void ListDestory(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}

//˫�������ӡ
void ListPrint(ListNode* phead)
{
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//˫������β��
void ListPushBack(ListNode* phead, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
	//ListInsert(phead, x);//����pos��ǰ����в���ʵ��β��
}

//˫������βɾ
void ListPopBack(ListNode* phead)
{
	assert(phead->next != phead);
	ListNode* tail = phead->prev; 
	ListNode* prev = tail->prev;
	free(tail);
	prev->next = phead;
	phead->prev = prev;
	//ListErase(phead->prev);//��ɾ��posλ�õĽڵ�ķ���ʵ��βɾ
}

//˫������ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* first = phead->next;
	phead->next = newnode;
	newnode->next = first;
	newnode->prev = phead;
	first->prev = newnode;
	//ListInsert(phead->next, x);//����pos��ǰ����в���ʵ��ͷ��
}

//˫������ͷɾ
void ListPopFront(ListNode* phead)
{
	assert(phead->next != phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;
	free(first);
	phead->next = second;
	second->prev = phead;
	//ListErase(phead->next);//��ɾ��posλ�õĽڵ�ķ���ʵ��ͷɾ
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	ListNode*cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	//����д��
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	newnode->next = pos;
	pos->prev = newnode;
	prev->next = newnode;
	newnode->prev = prev;

	//�������д��
	/*ListNode* newnode = BuyListNode(x);
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	pos->prev = newnode;
	newnode->next = pos;*/
}

// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}

void ListRemove(ListNode* phead, LTDataType x);