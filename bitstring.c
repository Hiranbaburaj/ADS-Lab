#include <stdio.h>

int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int b[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int i;

void reset(){ //reset both sets
    for(i=0;i<9;i++){
        a[i]=0;
        b[i]=0;
    }
}

void input(){
    reset();
    int n1, n2, x;
    printf("Enter the size of set 1 (MAX 9): ");
    scanf("%d",&n1);
    printf("Enter the size of set 2 (MAX 9): ");
    scanf("%d",&n2); 

    if((n1>9) || (n1<=0) || (n2>9) || (n2<=0)){
        printf("Enter Size from 1 to 9 ");
    }

    else{
        printf("\nEnter elements of set 1: \n");
        for(i = 0; i < n1; i++){
            printf("\nEnter element %d : ", i + 1);
            scanf("%d", &x);
            a[x-1] = 1;
        }
        printf("\nEnter elements of set 2: \n");        
        for(i = 0; i < n2; i++){
            printf("\nEnter element %d : ", i + 1);
            scanf("%d", &x);
            b[x-1] = 1;
        }
    }
}

void output(int o[]){
    printf("\n{ ");
    for(i=0;i<9;i++){
        if(o[i]==1){
            printf("%d, ", i+1);
        }
    }
    printf("} ");    
}

void uni(){
    int uni[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(i=0;i<9;i++){
        if(a[i] == 1 || b[i] == 1){
            uni[i]=1;
        }
    }
    printf("\nUnion of sets 1 & 2 are: ");
    output(uni);
}

void inter(){
	int inter[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	for(i = 0; i < 9; i++){
		if(a[i] == 1 && b[i] == 1){
			inter[i] = 1;
		}
	}
    printf("\nIntersection of sets 1 & 2 are: ");
    output(inter);
}

void diff(){
    int diff[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(i=0;i<9;i++){
        diff[i]=a[i];
        if(a[i] == 1 && b[i]==1){
            diff[i]=0;
        }
    }
    printf("\nDifference of sets 1 & 2 are: ");
    output(diff);
}

int main(){
	int choice = 0;
	
	while(choice != 5){
		printf("\n\nEnter your choice : \n1.Input\n2.Union\n3.Intersection\n4.Difference\n5.Exit\n");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: input();
				  break;
			case 2: uni();
				  break;
			case 3: inter();
				  break;
			case 4: diff();
				  break;
			case 5: printf("\nExit");
				  break;
				  
			default: printf("\nEnter a valid choice!");
		}
	}
}
