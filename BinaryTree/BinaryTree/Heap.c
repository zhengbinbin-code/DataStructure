#include"Heap.h"
#include<malloc.h>
#include<memory.h>

//С��
void AdjustDown(HpDataType* a, size_t n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//��С���Ǹ�����
		if (a[child + 1] < a[child])
		{
			++child;
		}
		//���ӱȸ���С
		if (a[child] < a[parent])
		{
			HpDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			//�Ѹ��׸�����,��������
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//���
void AdjustUp(HpDataType* a, size_t n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child + 1]>a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			HpDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

Heap* HeapCreate(HpDataType* a, size_t n)
{
	Heap* hp = (Heap*)malloc(sizeof(Heap));
	hp->_a = malloc(sizeof(HpDataType)*n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	//��С��
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
	return hp;
}

void HeapPush(Heap* hp, HpDataType x);
void HeapPop(Heap* hp);
HpDataType HeapTop(Heap* hp);

