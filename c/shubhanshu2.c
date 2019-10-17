#include<stdio.h>
void main()
{
int yr,j,ch,d=0;
scanf("%d",&yr);
for(j=2001;j<=yr;j++)
{
if(j%4==0)
{
if(j%100==0)
{
if(j%400==0)
d=d+366;
else
d=d+365;
}
else
d=d+366;
}
else
d=d+365;
}
ch=d%7;
switch(ch)
{
case 1:
printf("\nMonday\n");
break;
case 2:
printf("\nTueday\n");
break;
case 3:
printf("\nWednesday\n");
break;
case 4:
printf("\nThursday\n");
break;
case 5:
printf("\nFriday\n");
break;
case 6:
printf("\nSaturday\n");
break;
case 0:
printf("\nSunday\n");
break;
}

}
