#include<stdio.h>
int main()
{
int t,n1,n2,ans;
scanf("%d",&t);
while(t--)
{
scanf("%d%d",&n1,&n2);
ans=(reverse(n1)+reverse(n2));
printf("%d\n",reverse(ans));
}
return (0);
}
int reverse(int n)
{
int rev=0;
while(n>0)
{
rev=rev*10+n%10;
n=n/10;
}
return (rev);
}
