#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
main()
{
int*array;
int i,eureka;
printf("enter the size of array that you want to create\t");
scanf("%d",&eureka);
array=(int*)malloc(eureka*sizeof(int));
if(array==NULL)
  {
   printf("memory allocation failed");
   exit(1);
  }
else
printf("congrats array of size %d created succesfully\n",eureka);
for(i=0;i<eureka;i++)
   array[i]=10*(i+2);
for(i=0;i<eureka;i++)
  printf("%d\n",array[i]);

}


