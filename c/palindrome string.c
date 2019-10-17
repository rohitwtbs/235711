#include<stdio.h>
#include<string.h>
#include<conio.h>
void main()
{
char string[50],reverse[50];
int i;
printf("enter the string\t");
gets(string);
strcpy(reverse,string);
strrev(reverse);
i=stricmp(reverse,string);
if(i==0)
printf("the string entered is a palindrome");
else
printf("the enterted string is not a palindrome.");
getch();
}
