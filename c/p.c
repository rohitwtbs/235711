#include<stdio.h>
#include<math.h>
int main()
{
int count;
long int n,m,i,j,t;
scanf("%d",&t);
while(t--)
{
scanf("%d %d",&m,&n);
if(m==1||m==2)
    printf("%d\n",2);
if(m%2==0)
m=m+1;
for(i=m;i<=n;i=i+2)
{
count=0;
for(j=3;j<=sqrt(i);j=j+2)
if(i%j==0)
{count++;break;}
if(count==0&&i!=1)
printf("%d\n",i);
}
printf("\n");
}
return(0);
}
