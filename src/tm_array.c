#ifndef __TM_ARRAY__C
#define __TM_ARRAY__C123
#include<stdio.h>
#include<stdlib.h>
#include<tm_array.h>
Array *createArray(int *success)
{
Array *array;
if(success) *success=false;
array=(Array *)malloc (sizeof(Array));
if(array==NULL) return array;
array->rows=0;
array->size=0;
array->x=NULL;
if(success) *success=true;
return array;
}
void setElementOfArray(Array *array,int Index,void *element,int *success)
{
int rowsIndex,columnIndex;
int sp,ep,i;
void ***tmp;
if(success) *success=false;
rowsIndex=Index/10;
columnIndex=Index%10;
if(rowsIndex>=array->rows)
{
if(array->x!=NULL)
{
tmp=(void ***)calloc (rowsIndex+1,sizeof(void **));
if(tmp==NULL) return;
sp=0;
ep=array->rows-1;
for(i=sp;i<=ep;i++)
{
tmp[i]=array->x[i];
}
free(array->x);
array->x=tmp;
array->rows=rowsIndex+1;
}
else
{
array->x=(void ***)calloc (rowsIndex+1,sizeof(void **));
if(array->x==NULL) return;
array->rows=rowsIndex+1;
}
}
if(array->x[rowsIndex]==NULL) 
{
array->x[rowsIndex]=(void **)calloc (10,sizeof(void *));
}
array->x[rowsIndex][columnIndex]=element;
if(Index>=array->size) array->size=Index+1;
if(success) *success=true;
}
void *getElementOfArray(Array *array,int Index)
{
int rowsIndex,columnIndex;
if(array==NULL) return NULL;
if(array->x==NULL) return NULL;
rowsIndex=Index/10;
if(rowsIndex>=array->rows) return NULL;
if(array->x[rowsIndex]==NULL) return NULL;
columnIndex=Index%10;
return array->x[rowsIndex][columnIndex];
}
int getsizeOfArray(Array *array)
{
if(array==NULL) return 0;
return array->size;
}
void destroyArray(Array *array)
{
int i;
if(array==NULL) return;
if(array->x==NULL)
{
free(array);
return;
}
for(i=0;i<array->rows;i++)
{
if(array->x[i]!=NULL) free(array->x[i]);
}
free(array->x);
free(array);
}
#endif