#include"List.h"

//创建返回链表的头结点
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

//双向链表销毁
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

//双向链表打印
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

//双向链表尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
	//ListInsert(phead, x);//用在pos的前面进行插入实现尾插
}

//双向链表尾删
void ListPopBack(ListNode* phead)
{
	assert(phead->next != phead);
	ListNode* tail = phead->prev; 
	ListNode* prev = tail->prev;
	free(tail);
	prev->next = phead;
	phead->prev = prev;
	//ListErase(phead->prev);//用删除pos位置的节点的方法实现尾删
}

//双向链表头插
void ListPushFront(ListNode* phead, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* first = phead->next;
	phead->next = newnode;
	newnode->next = first;
	newnode->prev = phead;
	first->prev = newnode;
	//ListInsert(phead->next, x);//用在pos的前面进行插入实现头插
}

//双向链表头删
void ListPopFront(ListNode* phead)
{
	assert(phead->next != phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;
	free(first);
	phead->next = second;
	second->prev = phead;
	//ListErase(phead->next);//用删除pos位置的节点的方法实现头删
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

// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	//建议写法
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	newnode->next = pos;
	pos->prev = newnode;
	prev->next = newnode;
	newnode->prev = prev;

	//不建议的写法
	/*ListNode* newnode = BuyListNode(x);
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	pos->prev = newnode;
	newnode->next = pos;*/
}

// 删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}

void ListRemove(ListNode* phead, LTDataType x);