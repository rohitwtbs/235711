#include<stdio.h>
#include<math.h>
int main()
{
char station_name[50],memp,semp,lemp;
int j=0,temp,r,s,f,n,i,c;
printf("for how many trains u want to enter the data");

struct train_name
{
int no;
char name[50];
char start[50];
char stop[50];
};
struct train_name t[100];


for(i=0;i<=3;i++)
{
printf("enter the train no ,train name,start and stop");
fflush(stdin);
scanf("%d%s%s%S",&t[i].no,&t[i].name,&t[i].start,&t[i].stop);
}
for(i=0;i<=3;i++)
printf("%d%s%s%S",t[i].no,t[i].name,t[i].start,t[i].stop);
struct one
{
int no1;
char name1[50];
char start1[50];
char stop1[50];
};
struct one p[100];
printf("enter the station that you want to know");
scanf("%s[^\n]",station_name);
printf("%c",station_name);
for(c=0;c<=3;c++)
if(station_name==t[c].name)
{
t[c].no=p[j].no1;
j++;
}
printf("%d",3);
for(r=0;r<=3-1;r++)
for(s=0;s<=3-1-c;s++)
if(p[s].no1>p[s+1].no1)
{
temp=p[s].no1;
p[s].no1=p[s+1].no1;
p[s+1].no1=temp;
}
printf("the trains from the station in sorted order are as folows");
for(f=0;f<=3;f++);
printf("%d",p[f].no1);
}
