#include<stdio.h>
void main()
{
int i,j,n;
printf("enter the value of n");
scanf("%d",&n);
for(i=1;i<=n;i++)
 {
   {
    if((i&1)==0)
      {
       for(j=1;j<=i;j++)
       printf("# ");
       }
     else
      {
       for(j=1;j<=i;j++)
       printf("* ");
       }
     }
  printf("\n");
  }
}
