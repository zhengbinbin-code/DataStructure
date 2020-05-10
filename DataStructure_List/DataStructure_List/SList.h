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

//����һ��ָ��,ָ��SList
SListNode* pList;

//�����ʼ��
void SListInit(SListNode** pList);

//��������
void SListDestory(SListNode** pList);

//��ӡ����
void SListPrint(SListNode* pList);

//����һ���ڵ�
SListNode* BuySListNode(SLTDataType x);

//β��
void SListPushBack(SListNode** pList,SLTDataType x);

//ͷ��
void SListPushFront(SListNode** pList, SLTDataType x);

//βɾ
void SListPopBack(SListNode** pList);

//ͷɾ
void SListPopFront(SListNode** pList);

//ָ��ֵ����
SListNode* SListFind(SListNode* pList, SLTDataType x);

//ָ��λ�ú��
void SListInsertAfter(SListNode* pos, SLTDataType x);

//ָ��λ�ú�ɾ
void SListEraseAfter(SListNode* pos);

//ͳ�������е�Ԫ�ظ���
int GetListLength(SListNode* first);




//ɾ����һ��������ָ��ֵx
void SListRemove(SListNode** pList, SLTDataType x);

//ɾ������������ָ��ֵx
void SListRemoveAll(SListNode** pList, SLTDataType x);



  
