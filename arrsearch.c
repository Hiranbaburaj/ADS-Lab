//searching an array element

#include <stdio.h>
int arr[100],value,i,j,n,temp;

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

    printf("\nEnter an Element to search in the array: ");
    scanf("%d",&j);
    for(i=0;i<n;i++){
        if(arr[i]==j){
            printf("Given element present in array ");
            break;
        }

    }
    
    return 0;
}
