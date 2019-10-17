#include<stdio.h>
void main()
{
int i,j,sum,seriesum=0,p,n;
printf("enter the number");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
 p=2,sum=0;
for(j=1;j<=i;j++)
{
 sum=sum+pow(2,p);
 p=p+2;
}
seriesum=seriesum+sum;
}
printf("%d",seriesum);
}

