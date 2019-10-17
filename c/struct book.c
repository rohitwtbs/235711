#include<stdio.h>
int main()
{
struct book
{
char name;
float price;
int pages;
};
struct book b[100];
int i;
printf("enter name price and page");
for(i=0;i<=99;i++)
{
scanf("%c%f%d",&b[i].name,&b[i].price,&b[i].pages);
}
}
