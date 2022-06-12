#ifndef __TM_SLL__C
#define __TM_SLL__C 123
#include<tm_sll.h>
#include<stdlib.h>
SinglyLinkedList * createsinglyLinkedList(bool *success)
{
SinglyLinkedList *singlyLinkedList;
if(success) *success=false;
singlyLinkedList=(SinglyLinkedList *) malloc(sizeof(SinglyLinkedList));
if(singlyLinkedList==NULL) return NULL;
singlyLinkedList->start=NULL;
singlyLinkedList->end=NULL;
singlyLinkedList->size=0;
if(success) *success=true;
return singlyLinkedList;
}
void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
if(singlyLinkedList==NULL) return;
clearSinglyLinkedList(singlyLinkedList); 
free(singlyLinkedList);
}
int getsizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
if(singlyLinkedList==NULL) return 0;
return singlyLinkedList->size;
}
void clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
SinglyLinkedListNode *node;
if(singlyLinkedList==NULL) return;
node=singlyLinkedList->start;
while(singlyLinkedList->start!=NULL)
{
node=singlyLinkedList->start;
singlyLinkedList->start=singlyLinkedList->start->next;
free(node);
}
singlyLinkedList->size=0;
}
void addToSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,bool *success)
{
SinglyLinkedListNode *node;
if(success) *success=false;
if(singlyLinkedList==NULL) return;
node=(SinglyLinkedListNode*) malloc(sizeof(SinglyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->next=NULL;
if(singlyLinkedList->start==NULL)
{
singlyLinkedList->start=node;
singlyLinkedList->end=node;
}
else
{
singlyLinkedList->end->next=node;
singlyLinkedList->end=node;
}
singlyLinkedList->size++;
if(success) *success=false;
}
void insertIntoSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,int index,bool *success)
{
SinglyLinkedListNode *node,*p1,*p2;
int x;
if(success) *success=false;
if(singlyLinkedList==NULL) return;
if(index<0 || index>singlyLinkedList->size) return;
if(index==singlyLinkedList->size)
{
addToSinglyLinkedList(singlyLinkedList,ptr,success);
return;
}
node=(SinglyLinkedListNode*) malloc(sizeof(SinglyLinkedListNode));
if(node==NULL) return;
node->ptr=ptr;
node->next=NULL;
if(index==0)
{
node->next=singlyLinkedList->start;
singlyLinkedList->start=node;
singlyLinkedList->size++;
if(success) *success=true;
return;
}
x=0;
p1=singlyLinkedList->start;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
p2->next=node;
node->next=p1;
singlyLinkedList->size++;
if(success) *success=true;
}
void *removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success)
{
SinglyLinkedListNode *p1,*p2;
int x;
void *ptr;
if(success) *success=false;
if(singlyLinkedList==NULL) return NULL;
if(index<0 ||index>=singlyLinkedList->size) return NULL;
x=0;
p1=singlyLinkedList->start;
while(x<index)
{
p2=p1;
p1=p1->next;
x++;
}
ptr=p1->ptr;
if(singlyLinkedList->start==p1 && singlyLinkedList->end==p1)
{
singlyLinkedList->start==NULL;
singlyLinkedList->end==NULL;
}else if(singlyLinkedList->start==p1)
{
singlyLinkedList->start=singlyLinkedList->start->next;
}else if(singlyLinkedList->end==p1)
{
singlyLinkedList->end=p2;
singlyLinkedList->end->next=NULL;
}
else
{
p2->next=p1->next;
}
free(p1);
if(success) *success=true;
singlyLinkedList->size--;
return ptr;
}
void appendToSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList,SinglyLinkedList *sourceSinglyLinkedList,bool *success)
{
SinglyLinkedListNode *s,*e,*t,*node;
bool done;
if(success) *success=false;
if(targetSinglyLinkedList==NULL) return;
if(sourceSinglyLinkedList==NULL || sourceSinglyLinkedList->size==0)
{
if(success) *success=false;
return;
}
s=NULL;
e=NULL;
done=true;
t=sourceSinglyLinkedList->start;
while(t!=NULL)
{
node=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=t->ptr;
node->next=NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
e->next=node;
node=e;
}
t=t->next;
}
if(done==false)
{
while(s!=NULL)
{
node=s;
s=s->next;
free(node);
}
return;
}
if(targetSinglyLinkedList->start==NULL)
{
targetSinglyLinkedList->start=s;
targetSinglyLinkedList->end=e;
targetSinglyLinkedList->size=sourceSinglyLinkedList->size;
}
else
{
targetSinglyLinkedList->end->next=s;
targetSinglyLinkedList->end=e;
targetSinglyLinkedList->size+=sourceSinglyLinkedList->size;
}
if(success) *success=true;
}
void *getFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success)
{
SinglyLinkedListNode *node;
void *ptr;
int x;
if(success) *success=false;
if(singlyLinkedList==NULL) return NULL;
if(index<0 || index>=singlyLinkedList->size) return NULL;
x=0;
node=singlyLinkedList->start;
while(x<index)
{
node=node->next;
x++;
}
if(success) *success=false;
return node->ptr;
}
SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *singlyLinkedList,bool *success)
{
SinglyLinkedListIterator SinglyLinkedListIterator;
SinglyLinkedListIterator.node==NULL;
if(success) *success=false;
if(singlyLinkedList==NULL) return SinglyLinkedListIterator;
if(singlyLinkedList->start==NULL)
{
if(success) *success=true;
return SinglyLinkedListIterator;
}
if(success) *success=true;
SinglyLinkedListIterator.node=singlyLinkedList->start;
return SinglyLinkedListIterator;
}
bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator)
{
if(singlyLinkedListIterator==NULL) return false;
if(singlyLinkedListIterator->node==NULL) return false;
return true;
}
void *getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator,bool *success)
{
void *ptr=NULL;
if(success) *success=false;
if(singlyLinkedListIterator==NULL || singlyLinkedListIterator->node==NULL) return ptr;
ptr=singlyLinkedListIterator->node->ptr;
singlyLinkedListIterator->node=singlyLinkedListIterator->node->next;
if(success) *success=true;
return ptr;
}
#endif