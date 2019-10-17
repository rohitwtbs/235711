#include<stdio.h>
void main()
{
char line[50000];
printf("enter the line u want  to enter\n");
scanf("%[^\n]",line);
printf("the text u input was\n %s",line);
}
