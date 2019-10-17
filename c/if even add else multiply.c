#include<stdio.h>
void main()
{
int num[6],a=0,b=1,i;
printf("enter the five digit number");
for(i=0;i<=4;i++)
scanf("%d",&num[i]);
if((num[4]&1)==0)
 {
  for(i=0;i<=4;i++)
  a=a+num[i];
  printf("the sum of the numbers is=%d",a);
  }
else
  {
  for(i=0;i<=4;i++)
  b=b*num[i];
  printf("the product of the numbers is=%d",b);
  }
}
