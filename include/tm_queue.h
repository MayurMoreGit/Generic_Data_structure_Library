#ifndef __TM_QUEUE__H
#define __TM_QUEUE__H123
#include<tm_sll.h>
#include<tm_common.h>
typedef struct __$_tm_queue
{
SinglyLinkedList *singlyLinkedList;
}Queue;
Queue *createQueue(bool *success);
void addTOQueue(Queue *queue,void *ptr,bool *success);
void *removeFromQueue(Queue *queue,bool *success);
int getsizeOfQueue(Queue *queue);
void *elementAtFrontOfQueue(Queue *queue,bool *success);
bool isQueueempty(Queue *queue);
void clearQueue(Queue *queue);
void destroyQueue(Queue *queue);
#endif