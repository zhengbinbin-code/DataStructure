#pragma once
#include<stdio.h>

typedef int HpDataType;
typedef struct Heap
{
	HpDataType* _a;
	size_t _size;
	size_t _capacity;
}Heap;

void AdjustDown(HpDataType* a, size_t n, int root);
void HeapCreate(Heap* hp, HpDataType* a, size_t n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HpDataType x);
void HeapPop(Heap* hp);
HpDataType HeapTop(Heap* hp);
int HeapEmpty(Heap* hp);
void HeapPrint(Heap* hp);