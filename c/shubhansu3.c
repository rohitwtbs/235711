#include<stdio.h>
void main()
{
int a=65,i,j,k;
for(i=0;i<7;i++)
{
for(j=0;j<7-i;j++)
printf("%c",a++);
for(k=0;k<i;k++)
printf(" ");
for(k=0;k<i-1;k++)
printf(" ");
if(i==0)
{
a--;
j--;
}
for(j--;j>=0;j--)
printf("%c",--a);
printf("\n");
}

}
