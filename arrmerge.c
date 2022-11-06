#include <stdio.h>
int ar1[100],ar2[100],ar3[200],value,n,m,t,i;

int main(){
    printf("Enter the length of the first array: "); //first array
    scanf("%d",&n);
    printf("Enter the elements of the first array: \n");
    for(i=0;i<n;i++){
        
        scanf("%d",&value);
        ar1[i]=value;
    }
    printf("The first array is: ");
    for(i=0;i<n;i++){
        printf("%d",ar1[i]);
    }

    printf("\nEnter the length of the second array: "); //second array
    scanf("%d",&m);
    printf("Enter the elements of the second array: \n");
    for(i=0;i<m;i++){
        
        scanf("%d",&value);
        ar2[i]=value;
    }
    printf("The second array is: ");
    for(i=0;i<m;i++){
        printf("%d",ar2[i]);
    }

    t=m+n;
    for(i=0;i<n;i++){ //merged array
        ar3[i]=ar1[i];
    }
    for(i=n;i<t;i++){
        ar3[i]=ar2[i-n];
    }
    printf("\nThe merged array is: \n");
    for(i=0;i<t;i++){
        printf("%d",ar3[i]);
    }


}
