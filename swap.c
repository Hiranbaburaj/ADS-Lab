#include <stdio.h>
int arr[100],value,i,j,n,temp,x,y;

int main(){
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter array element %d: ",i);
        scanf("%d",&value);
        arr[i]=value;  
    }
    printf("The array elements are: ");

    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
printf("\nEnter the indexes you want to swap the elements of\n");

printf("Enter 1st index :");
    scanf("%d",&x);
printf("Enter 2nd index :");
    scanf("%d",&y);


if((x > n)||(y > n)){
	printf("Given index(s) do not exist");}
else{
	j=arr[x];
	arr[x]=arr[y];
	arr[y]=j;
	}
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}
