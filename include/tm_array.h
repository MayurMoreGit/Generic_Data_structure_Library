#ifndef __TM_ARRAY__H
#define __TM_ARRAY__H123
#include<tm_common.h>
typedef struct __array
{
int size;
void ***x;
int rows;
}Array;
Array *createArray(int *success);
void setElementOfArray(Array *array,int Index,void *element,int *success);
void *getElementOfArray(Array *array,int Index);
int getsizeOfArray(Array *array);
void destroyArray(Array *array);
#endif
