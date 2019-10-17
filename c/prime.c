#include<stdio.h>
int main()
{
int count;
long int n,m,i,j,t;
scanf("%d",&t);

while(t--)
{
scanf("%d %d",&m,&n);

for(i=m;i<=n;i++)
{
count=0;
for(j=2;j<i;j++)
if(i%j==0)
{count++;break;}
if(count==0&&i!=1)
printf("%d\n",i);
}
printf("\n");
}
return(0);
