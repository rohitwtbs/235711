#include<stdio.h>
void main()
{
int a=5,b=6,c;
printf("%d\t",a=b);
printf("%d/t",a==b);
printf("%d\t%d",a,b);
c=a++>b && ++b<10;
printf("%d%d%d",a,b,c);
}
