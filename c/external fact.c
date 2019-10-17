#include<stdio.h>
void main()
{
int i,first,second,third,a,sum;
i=1;
first=0;
second=1;
a=0;
sum=0;
printf("%d%d",first,second);
while(i<5)
 {
  third=first+second;
   first=second;
   second=third;
  printf("%d",third);
  i++;
  a++;
  sum=sum+third;
  }
printf("the sum is=%d",sum+1);
printf("the count is=%d",a+2);
}
