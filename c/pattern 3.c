#include<stdio.h>
void main()
{
int i,j,n,a=1,k=1,m;
printf("enter the no. of rows");
scanf("%d",&n);
for(i=4;i>=1;i--)
{
 {
 for(j=1;j<=i-1;j++)
 printf("  ");
 for(;k<=a;k++)
 printf("%d ",k);
 for(m=a-1;m>=k;m--)
 printf("%d ",m);
 }
 printf("\n");
 a=a+2;


 }
}
