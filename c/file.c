#include<stdio.h>
#include<stdlib.h>
main()
{
FILE *fp;
char ch[250];
int i=0;
fp=fopen("abc.txt","w+");
if(fp==NULL)
{
 printf("unable to create the  file\n");

}
printf(" enter the string");
scanf("%s[^\n]",&ch);
while(ch[i]!='\0')
fputc(ch[i++],fp);
fp=fopen("abc.txt","r");

}


