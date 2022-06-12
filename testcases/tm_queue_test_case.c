#include<stdio.h>
#include<tm_queue.h>
int main ()
{
int succ;
int x1,x2,x3,x4,x5,x6,x7;
char *x;
x1='a';
x2='B';
x3='F';
x4='D';
Queue *queue;
queue=createQueue(&succ);
if(queue==false)
{
printf("unable to create a queue\n");
return 0;
}
addTOQueue(queue,&x1,&succ);
if(succ) printf("%c push to add on queue\n",x1);
else printf("unable to push %c,on queue\n",x1);

addTOQueue(queue,&x2,&succ);
if(succ) printf("%c push to add on queue\n",x2);
else printf("unable to push %c,on queue\n",x2);

addTOQueue(queue,&x3,&succ);
if(succ) printf("%c push to add on queue\n",x3);
else printf("unable to push %c,on queue\n",x3);

addTOQueue(queue,&x4,&succ);
if(succ) printf("%c push to add on queue\n",x4);
else printf("unable to push %c,on queue\n",x4);


printf("sizeOfqueue %d\n",getsizeOfQueue(queue));
if(isQueueempty(queue)) printf("queue is empty\n");
else printf("queue is not empty\n");
x=(char *) elementAtFrontOfQueue(queue,&succ);
printf("element at front of queue%c\n",*x);
printf("remove all element of queue\n");
while(! isQueueempty(queue))
{
x=(char *) removeFromQueue(queue,&succ);
printf("%c popped from queue\n",*x);
}
destroyQueue(queue);
return 0;
}
