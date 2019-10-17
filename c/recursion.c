#include<stdio.h>
int fact(int);
void main()
{
int no,factorial;
printf("enter the number");
scanf("%d",&no);
for(no;no<=1;no--)
factorial=fact(no);
printf("factorial is",factorial);
}
int fact(int no)
{
int a;
a=no*fact(no-1);
if(no==1)
return 1;
else
return a;
}

