#include<stdio.h>
void main()
{
char ch[1000];
int i;
gets(ch);
for(i=0;ch[i]!='\0';i++)
if(ch[i]!='a' && ch[i]!='e' && ch[i]!='i' && ch[i]!='o' && ch[i]!='u')
printf("%c",ch[i]);
getch();
}
