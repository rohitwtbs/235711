#include<stdio.h>
void main()
{
int i,j,k,sum=0;
while(sum<20)
{
label1:
printf("\n\nEnter your no.");
scanf("%d",&i);
if(i>4 || i<1)
goto label1;
sum=sum+i;
printf("Total =%d",sum);
j=1;
while((sum+j)%5!=0)
{
j++;
}
printf("\nComputer select no. %d",j);
sum=sum+j;
printf("\nTotal =%d",sum);	
}
printf("\n\nYou hav to choose 1 so you loose");
getch();
}