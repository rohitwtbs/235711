#include<stdio.h>
main()
{
int arr[3][3],b[2]={1,0},i,j,k,m,n,z,win=0,count=0;
start:
for(z=0;;z++)
{
printf("computers chance");
while(count<=1)
{
if(arr[0][0]!=0&&arr[0][0]!=1)
{arr[0][0]=1;count++;goto show;}
if(arr[0][2]!=0&&arr[0][2])
{arr[0][2]=1;count++;goto show;}
if(arr[2][0]!=0&&arr[2][0]!=1)
{arr[2][0]=1;count++;goto show;}
if(arr[2][2]!=0&&arr[2][2]!=1)
{arr[2][2]=1;count++;goto show;}
}
for(i=0;i<=1;i++)
{
for(j=0;j<3;j++)
{
if((arr[j][0]==arr[j][1]==b[i])&&(arr[j][2]!=0&&arr[j][2]!=1))
{arr[j][2]=1;if(b[i]==1)win++;printf("%d",1);goto show;}
if((arr[j][0]==arr[j][2]==b[i])&&(arr[j][1]!=0&&arr[j][1]!=1))
{arr[j][1]=1;if(b[i]==1)win++;printf("%d",2);goto show;}
if((arr[j][1]==arr[j][2]==b[i])&&(arr[j][0]!=0&&arr[j][0]!=1))
{arr[j][0]=1;if(b[i]==1)win++;printf("%d",3);goto show;}
}
for(j=0;j<3;j++)
{
if((arr[0][j]==arr[1][j]==b[i])&&(arr[2][j]!=0&&arr[2][j]!=1))
{arr[2][j]=1;if(b[i]==1)win++;printf("%d",4);goto show;}
if((arr[0][j]==arr[2][j]&&arr[2][j]==0)&&(arr[1][j]!=0&&arr[1][j]!=1))
{arr[1][j]=1;if(b[i]==1)win++;printf("%d %d %d",5,b[i],j);goto show;}
if((arr[2][j]==arr[1][j]==b[i])&&(arr[0][j]!=0&&arr[0][j]!=1))
{arr[0][j]=1;if(b[i]==1)win++;printf("%d",6);goto show;}
}
for(j=0;j<2;j++)
{
if((arr[i][j]==arr[j+1][j+1]==b[i])&&(arr[j+2][j+2]!=0&&arr[j+2][j+2]!=1))
{arr[j+2][j+2]=1;if(b[i]==1)win++;printf("%d",7);goto show;}
if((arr[i][j]==arr[j+2][j+2]==b[i])&&(arr[j+1][j+1]!=0&&arr[j+1][j+1]!=1))
{arr[j+1][j+1]=1;if(b[i]==1)win++;printf("%d",8);goto show;}
if((arr[i+1][j+1]==arr[j+2][j+2]==b[i])&&(arr[j][j]!=0&&arr[j][j]!=1))
{arr[j][j]=1;if(b[i]==1)win++;printf("%d",9);goto show;}
}}
show:
printf("\nthe game is as folllows\n");
for(k=0;k<3;k++){
for(j=0;j<3;j++)
{
if(arr[k][j]==1)
printf("%d\t",1);
if(arr[k][j]==0)
printf("%d\t",arr[k][j]);
if(arr[k][j]!=1&&arr[k][j]!=0)
printf(" \t");
}printf("\n");}
if(win==1)
{
printf("\ncomputer wins\n");
break;}
pos:
printf("\nenter the position where u want to move\n");
scanf("%d%d",&m,&n);
if(arr[m][n]!=1&&arr[m][n]!=0)
arr[m][n]=0;
else
{
printf("wrong position,plz donot do chudurpana");
goto pos;
}
printf("\nthe game is as folllows\n");
     for(k=0;k<3;k++){
     for(j=0;j<3;j++)
     {
     if(arr[k][j]==1)
     printf("%d\t",1);
     if(arr[k][j]==0)
     printf("%d\t",arr[k][j]);
     if(arr[k][j]!=1&&arr[k][j]!=0)
      printf(" \t");
     }printf("\n");}
if(win==1)
{
printf("\ncomputer wins\n");
break;}
goto start;
}

}
