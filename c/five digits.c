#include<stdio.h>
void main()
{
long int num,a,b,c,d,e,f,g,h,eureka;
printf(" enter the five digit number");
scanf("%d",&num);
a=num/10000;
b=num%10000;
c=b/1000;
d=b%1000;
e=d/100;
f=d%100;
g=f/10;
h=f%10;
a=((a+1)%10)*10000;
c=((c+1)%10)*1000;
e=((e+1)%10)*100;
g=((g+1)%10)*10;
h=((h+1)%10)*1;
eureka=a+c+e+g+h;
printf("the increased no n is %d",eureka);
}
