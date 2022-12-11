//swap 2 arrays
#include<stdio.h>
int main()
{
int a[10],i,n,b[10],x;
printf("Enter the size of the array: ");
scanf("%d",&n);
printf("\nEnter array 1 elements: ");
for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

printf("\nEnter array 2 elements: ");
for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }

printf("\nArray 1 elements before Swapping: ");
for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

printf("\nArray 2 elements before Swapping: ");

for(i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }

for(i=0;i<n;i++)
{
    x=a[i];
    a[i]=b[i];
    b[i]=x;
}

printf("\nArray 1 elements after Swapping: ");
for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

printf("\nArray 2 elements after Swapping: ");

for(i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }

return 0;
}
