#include<stdio.h>
void main()
{
int i,j,t,r,k,n,g[10],x,sum=0;

printf("\nEnter the no of test cases");
scanf("%d",&t);

for(;t>0;t--)
{
printf("\nEnter the value of r,k,n");
scanf("%d %d %d",&r,&k,&n);
printf("\nEnter the Size of group");
for(i=0;i<n;i++)
scanf("%d",&g[i]);
x=0;
j=0;	
for(i=1;i<=r;i++)
{
while(x<=k)
{
x=x+g[j];
j++;
if(j==n)
j=0;
}
if(j==0)
j=n-1;
else
j--;
x=x-g[j];
sum+=x;
x=0;
}
printf("\n Euro = %d",sum);
sum=0;
}
getch();
}