#include<stdio.h>
void main()
{
int i,j=0,a[5];
scanf("%d",&i);
a[j]=i%10;
a[j]=a[j]+1;
a[j]=a[j]%10;
j++;
i/=10;
a[j]=i%100;
a[j]=a[j]+1;
a[j]=a[j]%10;
j++;
i/=10;
a[j]=i%1000;
a[j]=a[j]+1;
a[j]=a[j]%10;
j++;
i/=10;
a[j]=i%10000;
a[j]=a[j]+1;
a[j]=a[j]%10;
j++;
i/=10;
a[j]=i%100000;
a[j]=a[j]+1;
a[j]=a[j]%10;
j++;
printf("%d",a[0]+a[1]*10+a[2]*100+a[3]*1000+a[4]*10000);

}
