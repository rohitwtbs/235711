#include<stdio.h>
int binarysearch(int list[],int low,int high,int key);
void main()
{
int list[20],num,i,key,low,high,index;
printf("enter the number of elements(max 20)\t");
scanf("%d",&num);
printf("enter the elements in ascending order");
for(i=0;i<num;i++)
scanf("%d",&list[i]);
printf("enter the key that u want to search");
scanf("%d",&key);
index=binarysearch(list,0,num-1,key);
if (index==-1)
printf("does not exist in the list");
else
printf("exists at the location %d",index+1);
}
int binarysearch(int list[],int low,int high,int key)
{
int mid;
if(low==high)
{
if(list[low]==key)
return low;
else
return -1;
}
else
{
mid=(low+high)/2;
if(list[mid]==key)
return mid;
else if(list[mid]>key)
return binarysearch(list,low,mid-1,key);
else
return binarysearch(list,mid+1,high,key);
}
}


