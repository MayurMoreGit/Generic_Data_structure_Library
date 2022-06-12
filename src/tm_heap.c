#ifndef __TM_HEAP__C
#define __TM_HEAP__C123
#include<stdlib.h>
#include<tm_array.h>
#include<tm_heap.h>
Heap *createheap(int (* comparator)(void *,void *),int *success)
{
int succ;
Heap *heap=NULL;
if(success) *success=false;
if(comparator==NULL) return heap;
heap=(Heap *)malloc (sizeof(Heap));
if(heap==NULL) return heap;
heap->array=createArray(&succ);
if(!succ)
{
free(heap);
return NULL;
}
heap->comparator=comparator;
heap->size=0;
if(success) *success=true;
return heap;
}
void addToHeap(Heap *heap,void *element,int *success)
{
int weight,ci,ri,succ;
void *civalue,*rivalue;
if(success) *success=false;
if(heap==NULL) return;
setElementOfArray(heap->array,heap->size,element,&succ);
if(!succ) return;
heap->size++;
ci=heap->size-1;
while(ci>0)
{
ri=(ci-1)/2;
civalue=getElementOfArray(heap->array,ci);
rivalue=getElementOfArray(heap->array,ri);
weight=(heap->comparator(civalue,rivalue));
if(weight<0)
{
setElementOfArray(heap->array,ci,rivalue,&succ);
setElementOfArray(heap->array,ri,civalue,&succ);
ci=ri;
}
else
{
break;
}
}
if(success) *success=true;
}
void *removeFromHeap(Heap *heap,int *success)
{
int swi,ri,succ,upperbound,lci,rci;
void *element,*lastelement,*swivalue,*rivalue;
if(success) *success=false;
if(heap==NULL) return NULL;
if(heap->size==0) return NULL;
element=getElementOfArray(heap->array,0);
lastelement=getElementOfArray(heap->array,heap->size-1);
setElementOfArray(heap->array,0,lastelement,&succ);
heap->size--;
upperbound=heap->size-1;
ri=0;
while(ri<upperbound)
{
lci=(ri*2)+1;
if(lci>upperbound) break;
rci=lci+1;
if(rci>upperbound)
{
swi=lci;
}
else
{
if(heap->comparator(getElementOfArray(heap->array,lci),getElementOfArray(heap->array,rci))<0)
{
swi=lci;
}
else
{
swi=rci;
}
}
swivalue=getElementOfArray(heap->array,swi);
rivalue=getElementOfArray(heap->array,ri);
if(heap->comparator(swivalue,rivalue)<0)
{
setElementOfArray(heap->array,swi,rivalue,&succ);
setElementOfArray(heap->array,ri,swivalue,&succ);
ri=swi;
}
else
{
break;
}
}
if(success) *success=true;
return element;
}
void *elementAtTopOfHeap(Heap *heap,int *success)
{
if(success) *success=false;
if(heap==NULL) return NULL;
if(heap->size=0) return NULL;
if(success) *success=true;
return getElementOfArray(heap->array,0);
}
int getSizeOfHeap(Heap *heap)
{
if(heap==NULL) return 0;
return heap->size;
}
void *getElementOfHeap(Heap *heap,int index,int *success)
{
void *element=NULL;
if(success) *success=false;
if(heap==NULL) return element;
if(index<0 || index>heap->size) return element;
element=getElementOfArray(heap->array,index);
if(success) *success=true;
return element;
}
void updateElementInHeap(Heap *heap,int index,void *element,int *success)
{
int swi,ri,succ,upperbound,lci,rci,goDown,weight,ci;
void *lastelement,*swivalue,*rivalue,*civalue;
if(success) *success=false;
if(heap==NULL) return;
if(index<0 || index>heap->size) return;
setElementOfArray(heap->array,index,element,&succ);
if(index==0)
{
goDown=true;
}
else if(heap->size-1)
{
goDown=false;
}
ci=index;
ri=(ci-1)/2;
civalue=getElementOfArray(heap->array,ci);
rivalue=getElementOfArray(heap->array,ri);
weight=(heap->comparator(civalue,rivalue));
if(weight<0) goDown==false;
else goDown==true;
}
if(goDown)//head to heapfy
{
upperbound=index;
ri=0;
while(ri<upperbound)
{
lci=(ri*2)+1;
if(lci>upperbound) break;
rci=lci+1;
if(rci>upperbound)
{
swi=lci;
}
else
{
if(heap->comparator(getElementOfArray(heap->array,lci),getElementOfArray(heap->array,rci))<0)
{
swi=lci;
}
else
{
swi=rci;
}
}
swivalue=getElementOfArray(heap->array,swi);
rivalue=getElementOfArray(heap->array,ri);
if(heap->comparator(swivalue,rivalue)<0)
{
setElementOfArray(heap->array,swi,rivalue,&succ);
setElementOfArray(heap->array,ri,swivalue,&succ);
ri=swi;
}
else
{
break;
}
}
}
else
{
ci=index;
while(ci>0)
{
ri=(ci-1)/2;
civalue=getElementOfArray(heap->array,ci);
rivalue=getElementOfArray(heap->array,ri);
weight=(heap->comparator(civalue,rivalue));
if(weight<0)
{
setElementOfArray(heap->array,ci,rivalue,&succ);
setElementOfArray(heap->array,ri,civalue,&succ);
ci=ri;
}
else
{
break;
}
}
}
if(success) *success=true;
}
void destroyHeap(Heap *heap)
{
if(heap==NULL) return;
destroyArray(heap->array);
free(heap);
}
#endif 
