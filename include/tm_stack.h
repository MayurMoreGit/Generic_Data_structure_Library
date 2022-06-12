#ifndef __TM_STACK__H
#define __TM_STACK__H123
#include<tm_sll.h>
#include<tm_common.h>
typedef struct __$_tm_stack
{
SinglyLinkedList *singlyLinkedList;
}Stack;
Stack *createStack(bool *success);
void pushOnStack(Stack *stack,void *ptr,bool *success);
void *popfromStack(Stack *stack,bool *success);
int getsizeOfStack(Stack *stack);
void *elementAtTopOfStack(Stack *stack,bool *success);
bool isStackempty(Stack *stack);
void clearStack(Stack *stack);
void destroyStack(Stack *stack);
#endif