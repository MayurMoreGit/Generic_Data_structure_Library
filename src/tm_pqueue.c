#ifndef __TM_PQUEUE__C
#define __TM_PQUEUE__C123
#include<tm_heap.h>
#include<tm_pqueue.h>
#include<stdlib.h>
PQueue *createPQueue(int (*predicate) (void *,void *),bool *success)
{
PQueue *pQueue;
Heap*heap;
heap=createheap(predicate,success);
if(*success==false) return NULL;
pQueue=(PQueue*)malloc (sizeof(PQueue));
if(pQueue==NULL)
{
destroyHeap(heap);
if(success) *success=false;
return NULL;
}
pQueue->heap=heap;
if(success) *success=true;
return pQueue;
}
void addToPQueue(PQueue *pQueue,void *ptr,bool *success)
{
if(success) *success=false;
if(pQueue==NULL || pQueue->heap==NULL) return;
addToHeap(pQueue->heap,ptr,success);
}
void *removeFromPQueue(PQueue *pQueue,bool *success)
{
void *ptr;
if(success) *success=false;
if(isPQueueempty(pQueue)) return NULL;
ptr=removeFromHeap(pQueue->heap,success);
if(success) *success=true;
return ptr;
}
int getsizeOfPQueue(PQueue *pQueue)
{
if(pQueue==NULL || pQueue->heap==NULL) return 0;
return getSizeOfHeap(pQueue->heap);
}       
void *elementAtFrontOfPQueue(PQueue *pQueue,bool *success)
{
void *ptr;
if(success) *success=false;
if(isPQueueempty(pQueue)) return NULL;
ptr=elementAtTopOfHeap(pQueue->heap,success);
if(success) *success=true;
return ptr;
}
bool isPQueueempty(PQueue*pQueue)
{
if(pQueue==NULL) return true;
if(pQueue->heap==NULL) return true;
if(getSizeOfHeap(pQueue->heap)==0) return true;
return false;
}
void clearPQueue(PQueue *pQueue)
{
int *success;
if(pQueue==NULL) return;
if(pQueue->heap==NULL) return;
while(getSizeOfHeap(pQueue->heap)>0)
{
removeFromHeap(pQueue->heap, success);
}
}
void destroyPQueue(PQueue *pQueue)
{
if(pQueue==NULL) return;
if(pQueue->heap==NULL) return;
destroyHeap(pQueue->heap);
free(pQueue);
}
#endif