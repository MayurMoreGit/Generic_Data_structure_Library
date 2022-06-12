#ifndef __TM_HEAP__H
#define __TM_HEAP__H123
#include<tm_common.h>
typedef struct __heap
{
Array *array;
int (*comparator) (void *,void *);
int size;
}Heap;
Heap *createheap(int (*comparator) (void *,void*),int *success);
void addToHeap(Heap *heap,void *element,int *success);
void *removeFromHeap(Heap *heap,int *success);
void *elementAtTopOfHeap(Heap *heap,int *success);
int getSizeOfHeap(Heap *heap);
void *getElementOfHeap(Heap *heap,int index,int *success);
void updateElementInHeap(Heap *heap,int index,void *element,int *success);
void destroyHeap(Heap *heap);
#endif