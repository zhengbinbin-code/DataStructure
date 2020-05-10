#include"SList.h"
#include"List.h"

void TestSList()
{
	SListInit(&pList);

	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	SListPopFront(&pList);
	SListPrint(pList);

	SListNode* ret = SListFind(pList, 2);
	SListInsertAfter(ret, 20);
	SListPrint(pList);

	GetListLength(pList);

	SListDestory(&pList);
	SListPrint(pList);

}

void TestList()
{
	ListNode* list = ListCreate();
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPushBack(list, 5);
	ListPrint(list);

	ListPopBack(list);
	ListPopBack(list);
	ListPopBack(list);
	ListPrint(list);

	ListPushFront(list, 1);
	ListPushFront(list, 2);
	ListPushFront(list, 3);
	ListPushFront(list, 1);
	ListPushFront(list, 2);
	ListPushFront(list, 3);
	ListPrint(list);

	ListPopFront(list);
	ListPopFront(list);
	ListPopFront(list);
	ListPrint(list);

}

int main()
{
	//TestSList();
	TestList();

	system("pause");
	return 0;
}