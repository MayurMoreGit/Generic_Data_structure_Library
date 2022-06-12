#include<stdio.h>
#include<tm_sll.h>
int main ()
{
int *x;
int i1,i2,i3,i4,i5,i6,y;
bool succ;
SinglyLinkedList *list1,*list2;
list1=createsinglyLinkedList(&succ);
list2=createsinglyLinkedList(&succ);
i1=100;
i2=200;
i3=300;
i4=400;
i5=500;
i6=600;                                        
addToSinglyLinkedList(list1,(void *)&i1,&succ);
addToSinglyLinkedList(list2,(void *)&i2,&succ);
addToSinglyLinkedList(list1,(void *)&i3,&succ);
addToSinglyLinkedList(list2,(void *)&i2,&succ);
addToSinglyLinkedList(list1,(void *)&i5,&succ);
addToSinglyLinkedList(list2,(void *)&i2,&succ);
appendToSinglyLinkedList(list1,list2,&succ);
if(succ) printf(" unable to append\n"); else printf("append\n");
for(y=0;y<getsizeOfSinglyLinkedList(list1);y++)
{
x=(int *)getFromSinglyLinkedList(list1,y,&succ);
printf("%d\n",*x);
}
printf("**********\n");
for(y=0;y<getsizeOfSinglyLinkedList(list2);y++)
{
x=(int *)getFromSinglyLinkedList(list2,y,&succ);
printf("%d\n",*x);
}
destroySinglyLinkedList(list1);
return 0;
}