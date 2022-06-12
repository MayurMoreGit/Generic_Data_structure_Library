#include<stdio.h>
#include<tm_heap.h>
int mycomparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
}
int main ()
{
int x1,x2,x3,x4,x5;
int succ,i;
int *ptr;
Heap *heap;
heap=createheap(mycomparator,&succ);
if(!succ)
{
printf("low memory allocated : ");
return  0;
}
x1=600;
x2=2000;
x3=2;
x4=800;
x5=500;
addToHeap(heap,&x1,&succ);
addToHeap(heap,&x2,&succ);
addToHeap(heap,&x3,&succ);
addToHeap(heap,&x4,&succ);
addToHeap(heap,&x5,&succ);
for(i=0;i<getSizeOfHeap(heap);i++)
{
ptr=getElementOfHeap(heap,i,&succ);
printf("%d\n",*ptr);
}
printf("now updating : ");
x4=200;
updateElementInHeap(heap,i,(void *)&x4,&succ);
for(i=0;i<getSizeOfHeap(heap);i++)
{
ptr=getElementOfHeap(heap,0,&succ);
printf("%d\n",*ptr);
}
return 0;
}