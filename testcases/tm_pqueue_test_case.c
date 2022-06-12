#include<stdio.h>
#include<tm_pQueue.h>
int mycomparator(void *left,void *right)
{
int *a,*b;
a=(int *)left;
b=(int *)right;
return (*a)-(*b);
}
int main ()
{
int x1,x2,x3,x4;
int succ;
int *ptr;
PQueue *pQueue;
pQueue=createPQueue(mycomparator,&succ);
if(!succ)
{
printf("low memory allocated : ");
return  0;
}
x1=60;
x2=570;
x3=2090;
x4=-28;
addToPQueue(pQueue,&x1,&succ);
addToPQueue(pQueue,&x2,&succ);
addToPQueue(pQueue,&x3,&succ);
addToPQueue(pQueue,&x4,&succ);
while(getsizeOfPQueue(pQueue)>0)
{
ptr=removeFromPQueue(pQueue,&succ);
printf("%d\n",*ptr);
}
return 0;
}