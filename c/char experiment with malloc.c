#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
main()
{
char*array;
int i,eureka;
printf("enter the size of array that you want to create\t");
scanf("%d",&eureka);
array=(char*)malloc(eureka*sizeof(char));
if(array==NULL)
  {
   printf("memory allocation failed");
   exit(1);
  }
else
printf("congrats array of size %d created succesfully\n",eureka);
for(i=0;i<eureka;i++)
scanf("%s[^\n]",array[i]);
for(i=0;i<eureka;i++)
  printf("%s",array[i]);

}


