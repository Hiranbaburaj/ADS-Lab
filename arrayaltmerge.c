#include<stdio.h>
void main()
{
int a[10],i,n,b[10],merge[20],x,i1;
printf("enter the size of the array: \n");
scanf("%d",&n);
printf("enter the array elements: \n");
for(i=0;i<n;i++)

{
scanf("%d",&a[i]);
}

printf("array 1 elements are: \n");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}

printf("enter the array elements \n");
for(i=0;i<n;i++)

{
scanf("%d",&b[i]);
}

printf("array 2 elements are: \n");
for(i=0;i<n;i++)
{
printf("%d ",b[i]);
}

x=n+n;

for(i = 0 , i1 = 0 ; i < x; i++ , i1++)
{
    merge[i]=a[i1];
    i++;
    merge[i]=b[i1];
}
        
printf("\n The merged array: \n");
for(int i = 0; i < x; i++)
printf("%d ", merge[i]);

}
