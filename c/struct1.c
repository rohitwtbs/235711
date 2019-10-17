#include<stdio.h>
int main()
{
struct train_info
{
int trainno;
char name[50];
char arrival[50];
char depart[50];
};
struct train_info t[2];
int i;
fflush(stdin);
for(i=0;i<=1;i++)
{
printf("enter the train number\n");
scanf("%d",&t[i].trainno);
printf("enter the name of the train\n ");
scanf("%[^\n]",t[i].name);
printf("\n enter the start station");
gets(t[i].arrival);
}
printf("%d\n",t[0].trainno);
printf("%c\n",t[0].arrival);
}
