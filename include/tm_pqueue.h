#ifndef __TM_PQUEUE__H
#define __TM_PQUEUE__H123
#include<tm_heap.h>
#include<tm_common.h>
typedef struct __$_tm_pQueue
{
Heap *heap;
}PQueue;
PQueue *createPQueue(int (*predicate) (void *,void *),bool *success);
void addToPQueue(PQueue *pQueue,void *ptr,bool *success);
void *removeFromPQueue(PQueue *pQueue,bool *success);
int getsizeOfPQueue(PQueue *pQueue);
void *elementAtFrontOfPQueue(PQueue *pQueue,bool *success);
bool isPQueueempty(PQueue *pQueue);
void clearPQueue(PQueue *pQueue);
void destroyPQueue(PQueue *pQueue);
#endif