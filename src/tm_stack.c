#ifndef __TM_STACK__C
#define __TM_STACK__C123
#include<tm_sll.h>
#include<tm_stack.h>
#include<stdlib.h>
Stack *createStack(bool *success)
{
Stack *stack;
SinglyLinkedList *singlyLinkedList;
singlyLinkedList=createsinglyLinkedList(success);
if(*success==false) return NULL;
stack=(Stack*)malloc (sizeof(stack));
if(stack==NULL)
{
destroySinglyLinkedList(singlyLinkedList);
if(success) *success=false;
return NULL;
}
stack->singlyLinkedList=singlyLinkedList;
if(success) *success=true;
return stack;
}
void pushOnStack(Stack *stack,void *ptr,bool *success)
{
if(success) *success=false;
if(stack==NULL || stack->singlyLinkedList==NULL) return;
insertIntoSinglyLinkedList(stack->singlyLinkedList,ptr,0,success);
}
void *popfromStack(Stack *stack,bool *success)
{
void *ptr;
if(success) *success=false;
if(isStackempty(stack)) return NULL;
ptr=removeFromSinglyLinkedList(stack->singlyLinkedList,0,success);
if(success) *success=true;
return ptr;
}
int getsizeOfStack(Stack *stack)
{
if(stack==NULL || stack->singlyLinkedList==NULL) return 0;
return getsizeOfSinglyLinkedList(stack->singlyLinkedList);
}       
void *elementAtTopOfStack(Stack *stack,bool *success)
{
void *ptr;
if(success) *success=false;
if(isStackempty(stack)) return NULL;
ptr=getFromSinglyLinkedList(stack->singlyLinkedList,0,success);
if(success) *success=true;
return ptr;
}
bool isStackempty(Stack*stack)
{
if(stack==NULL) return true;
if(stack->singlyLinkedList==NULL) return true;
if(getsizeOfSinglyLinkedList(stack->singlyLinkedList)==0) return true;
return false;
}
void clearStack(Stack *stack)
{
if(stack==NULL) return;
if(stack->singlyLinkedList==NULL) return;
clearSinglyLinkedList(stack->singlyLinkedList);
}
void destroyStack(Stack *stack)
{
if(stack==NULL) return;
if(stack->singlyLinkedList==NULL) return;
destroySinglyLinkedList(stack->singlyLinkedList);
free(stack);
}
#endif