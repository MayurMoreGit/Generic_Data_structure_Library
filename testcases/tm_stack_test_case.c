#include<stdio.h>
#include<tm_stack.h>
int main ()
{
int succ;
char x1,x2,x3,x4,x5,x6,x7;
char *x;
x1='a';
x2='B';
x3='F';
x4='D';
Stack *stack;
stack=createStack(&succ);
if(stack==false)
{
printf("unable to create a stack\n");
return 0;
}
pushOnStack(stack,&x1,&succ);
if(succ) printf("%c push to add on stack\n",x1);
else printf("unable to push %c,on stack\n",x1);

pushOnStack(stack,&x2,&succ);
if(succ) printf("%c push to add on stack\n",x2);
else printf("unable to push %c,on stack\n",x2);

pushOnStack(stack,&x3,&succ);
if(succ) printf("%c push to add on stack\n",x3);
else printf("unable to push %c,on stack\n",x3);

pushOnStack(stack,&x4,&succ);
if(succ) printf("%c push to add on stack\n",x4);
else printf("unable to push %c,on stack\n",x4);


printf("sizeOfstack %d\n",getsizeOfStack(stack));
if(isStackempty(stack)) printf("stack is empty\n");
else printf("stack is not empty\n");
x=(char *) elementAtTopOfStack(stack,&succ);
printf("element at top of stack%c\n",*x);
printf("popped all element of stack\n");
while(! isStackempty(stack))
{
x=(char *) popfromStack(stack,&succ);
printf("%c popped from stack\n",*x);
}
destroyStack(stack);
return 0;
}