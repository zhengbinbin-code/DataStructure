#include<stdio.h>
#include"Heap.h"

//降序
void HeapSort(int* a, int n)
{
	//建小堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		int tmp = a[end];
		a[end] = a[0];
		a[0] = tmp;
		AdjustDown(a, end, 0);
		--end;
	}
}

void PrintTopK(int* a, int n, int k)
{
	//建k个数的小堆
	Heap hp;
	HeapCreate(&hp, a, k);
	for (int i = k; i < n; ++i)
	{
		if (HeapTop(&hp) < a[i])
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	HeapPrint(&hp);
}

void TestTopK()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	a[5] = 1000000 + 1;
	a[22] = 1000000 + 2;
	a[358] = 1000000 + 3;
	a[154] = 1000000 + 4;
	a[886] = 1000000 + 5;
	a[5153] = 1000000 + 6;
	a[8716] = 1000000 + 7;
	a[389] = 1000000 + 8;
	a[2154] = 1000000 + 9;
	a[1468] = 1000000 + 10;
	PrintTopK(a, n, 10);
}

int main()
{
	int a[10] = { 27, 15, 19, 34, 65, 37, 25, 49, 28, 18 };
	int n = sizeof(a) / sizeof(a[0]);
	//HeapSort(a, n);

	/*Heap hp;
	HeapCreate(&hp, a, n);
	HeapPush(&hp, 9);
	HeapPush(&hp, 99);
	HeapPush(&hp, 0);
	HeapPrint(&hp);
	
	HeapPop(&hp);
	HeapPrint(&hp);*/

	/*Heap hp;
	HeapCreate(&hp, a, n);
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}*/

	//TestTopK();

	system("pause");
	return 0;
}