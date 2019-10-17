#include<stdio.h>
void main()
{
int array1[10][10],array2[10][10],array3[10][10],array4[10][10],i,j,m,n,b=0;
printf("enter the size of the array");
scanf("%d%d",&m,&n);
printf("enter the elements of array1");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%d",&array1[i][j]);
printf("enter the elements of array2");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%d",&array2[i][j]);
for(i=0;i<m;i++)
for(j=0;j<n;j++)
array3[i][j]=array1[i][j]+array2[i][j];
printf("the elements of matrices after adding the two matrix are\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
printf("%d\t",array3[i][j]);
printf("\n");
}

for(i=0;i<m;i++)
b=b+array3[i][i];
printf("the sum of principal diagonal of the square mattrix is=%d",b);
for(i=0;i<m;i++)
for(j=0;j<m;j++)
if(i<=j)
array4[i][j]=array3[i][j];
else
array4[i][j]=0;
printf("\nthe upper half triangular matrix is\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
printf("%d\t",array4[i][j]);
printf("\n");
}
}

