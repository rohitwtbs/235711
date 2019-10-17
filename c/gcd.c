#include<stdio.h>
void main()
{
int a,b,c,d,e,f,i;
scanf("%d%d%d",&a,&b,&c);
for(i=a;i>=1;i--)
{
  d=a%i;
  e=b%i;
  f=c%i;
 if((d==0)&&(e==0)&&(f==0))
 {
 printf("the GCD(greatest common divisor) of the numbers is=%d",i);
  break;
 }

 }
}
