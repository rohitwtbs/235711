#include<stdio.h>
#include<malloc.h>
void main()
{
int *array,size,i;
printf("enter the size of the array");
scanf("%d",&size);
array=(int*)malloc(size*sizeof(int));
printf("enter the elements");
for(i=0;i<size;i++)
scanf("%d",&array[i]);
for(i=size-1 ;i>=0;i--)
printf("%d",array[i]);
}
