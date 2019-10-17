#include<stdio.h>
void main()
{
int i,j,k,f=1;
for(i=65;i<=71;i++)
printf("%c ",i);
for(i=70;i>=65;i--)
printf("%c ",i);
printf("\n");
for(i=1;i<=6;i++)
{
  {
   for(j=65;j<=71-i;j++)
   printf("%c ",j);
   }
     {
      for(k=1;k<=f;k++)
       printf("  ");
       f=f+2;
      for(k=71-i;k>=65;k--)
      printf("%c ",k);
     }
 printf("\n");
}
}
