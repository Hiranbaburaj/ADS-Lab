//sorting an array

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

    for(i=n;i>0;i--){
        for(j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){	
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			}
        }
    }
    printf("The array elements are: ");

    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}
