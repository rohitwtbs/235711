#include<stdio.h>
#include<conio.h>
int fact(int i);
int main()
{
int sum=0 ,i,n,e;
printf("enter the no. til u want the series");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
e=fact(i);
sum=e+sum;
}
printf("the sum of the series is  %d",sum);
}
int fact(int i)
{
int t,j,a=1,d=0;
for(t=1;t<=i;t++)
{
for(j=1;j<=t;j++)
{
a=a*j;

}
d=d+a;
a=1;
printf("%d \n",d);
}
return(d);
}
