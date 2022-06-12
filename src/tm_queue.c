#ifndef __TM_QUEUE__C
#define __TM_QUEUE__C123
#include<tm_sll.h>
#include<tm_queue.h>
#include<stdlib.h>
Queue *createQueue(bool *success)
{
Queue *queue;
SinglyLinkedList *singlyLinkedList;
singlyLinkedList=createsinglyLinkedList(success);
if(*success==false) return NULL;
queue=(Queue*)malloc (sizeof(Queue));
if(queue==NULL)
{
destroySinglyLinkedList(singlyLinkedList);
if(success) *success=false;
return NULL;
}
queue->singlyLinkedList=singlyLinkedList;
if(success) *success=true;
return queue;
}
void addTOQueue(Queue *queue,void *ptr,bool *success)
{
if(success) *success=false;
if(queue==NULL || queue->singlyLinkedList==NULL) return;
addToSinglyLinkedList(queue->singlyLinkedList,ptr,success);
}
void *removeFromQueue(Queue *queue,bool *success)
{
void *ptr;
if(success) *success=false;
if(isQueueempty(queue)) return NULL;
ptr=removeFromSinglyLinkedList(queue->singlyLinkedList,0,success);
if(success) *success=true;
return ptr;
}
int getsizeOfQueue(Queue *queue)
{
if(queue==NULL || queue->singlyLinkedList==NULL) return 0;
return getsizeOfSinglyLinkedList(queue->singlyLinkedList);
}       
void *elementAtFrontOfQueue(Queue *queue,bool *success)
{
void *ptr;
if(success) *success=false;
if(isQueueempty(queue)) return NULL;
ptr=getFromSinglyLinkedList(queue->singlyLinkedList,0,success);
if(success) *success=true;
return ptr;
}
bool isQueueempty(Queue*queue)
{
if(queue==NULL) return true;
if(queue->singlyLinkedList==NULL) return true;
if(getsizeOfSinglyLinkedList(queue->singlyLinkedList)==0) return true;
return false;
}
void clearQueue(Queue *queue)
{
if(queue==NULL) return;
if(queue->singlyLinkedList==NULL) return;
clearSinglyLinkedList(queue->singlyLinkedList);
}
void destroyQueue(Queue *queue)
{
if(queue==NULL) return;
if(queue->singlyLinkedList==NULL) return;
destroySinglyLinkedList(queue->singlyLinkedList);
free(queue);
}
#endif