#include"Heap.h"
#include<malloc.h>
#include<memory.h>
#include<stdlib.h>
#include<time.h>

void Swap(int* a, int* b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

//С��
void AdjustDown(HpDataType* a, size_t n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//��С���Ǹ�����
		if (child + 1 < n && a[child + 1] < a[child])
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

void HeapCreate(Heap* hp, HpDataType* a, size_t n)
{
	hp->_a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	memcpy(hp->_a, a, sizeof(HpDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	//��С��
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_capacity = hp->_size = 0;
	hp->_a = NULL;
}

void AdjustUp(int* a, int child)
{

	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			HpDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* hp, HpDataType x)
{
	//�ռ䲻����������
	if (hp->_size == hp->_capacity)
	{
		size_t newcapacity = hp->_capacity * 2;
		hp->_a = (HpDataType*)realloc(hp->_a, sizeof(HpDataType)*newcapacity);
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//���ϵ��������ɶ�
	AdjustUp(hp->_a, hp->_size - 1);
}

void HeapPop(Heap* hp)
{
	HpDataType tmp = hp->_a[0];
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = tmp;
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}

HpDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}

//��ӡ��
void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}


