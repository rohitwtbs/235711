#include<stdio.h>
void main()
{
int year,i,count,sub;
count=0;
printf("enter the year for which u want the day");
scanf("%d",&year);
for(i=2001;i<year;i++)
{
if((i%4==0)&&(i%100!=0)||(i%400==0))
count=count+1;
}
printf("the value of count is%d",count);
sub=year-2001;
sub=sub+count;
if(sub>7)
{
sub=sub-7;
}
switch(sub)
{
case1:
printf("tuesday");
break;
case2:
printf("wednesday");
break;
case3:
printf("thursday");
break;
case4:
printf("friday");
break;
case5:
printf("saturday");
break;
case6:
printf("sunday");
break;
case7:
printf("monday");
break;
}
}
