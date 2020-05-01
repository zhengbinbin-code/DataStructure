#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<assert.h>

typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front; // ��ͷ
	QueueNode* _back; // ��β
}Queue;

//��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;
}

//��β�����
void QueuePush(Queue* q, QUDataType x)
{
	assert(q);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = x;
	newnode->_next = NULL;
	if (q->_back == NULL)
	{
		q->_front = q->_back = newnode;
	}
	else
	{
		q->_back->_next = newnode;
		q->_back = newnode;
	}
}

//��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front->_next == NULL)
	{
		free(q->_front);
		q->_front = q->_back = NULL;
	}
	else
	{
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
	}
}

//��ȡ����ͷ��Ԫ��
QUDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

//��ȡ����β��Ԫ��
QUDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_back->_data;
}

//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	int n = 0;
	QueueNode* cur = q->_front;
	while (cur)
	{
		n++;
		cur = cur->_next;
	}
	return n;
}

//�������Ƿ�Ϊ�գ����Ϊ�շ��ط���(1)�������Ϊ�շ���0
int QueueEmpty(Queue* q)
{
	return q->_front == NULL ? 1 : 0;
}

//���ٶ���
void QueueDestroy(Queue* q)
{
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = cur->_next;
	}
	q->_front = q->_back = NULL;
}

//����һ�����нڵ�
QueueNode* BuyQueueNode(QUDataType x);

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

	QueueDestroy(&q);
}