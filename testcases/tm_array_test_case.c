#include<stdio.h>
#include<tm_array.h>
int main ()
{
int *x;
int succ;
int i;
int x1,x2,x3,x4;
/*x1=100;
x2=200;
x3=300;
x4=400;*/
Array *array;
array=createArray(& succ);
if(!succ)
{
printf("memory not allocated\n");
}
else
{
printf("memory allocated\n");
}
setElementOfArray(array,10,(void *)1030,&succ);
setElementOfArray(array,70,(void *)2030,&succ);
setElementOfArray(array,7,(void *)2000,&succ);
setElementOfArray(array,100,(void *)2101,&succ);
for(i=0;i<getsizeOfArray(array);i++)
{
x=(int *)getElementOfArray(array,i);
printf("(%d---->%d)\n",i,getElementOfArray(array,i));;
}
return 0;
}
