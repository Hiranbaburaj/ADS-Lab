#include <stdio.h>
int q[100],front,rear,n,i,choice,value;
void enqueue(void);
void dequeue(void);
void display(void);

int main(){
    printf("Enter the no of elements in the Queue: ");
    scanf("%d",&n);
    rear=-1;
    front=0;
    do{
        printf("\n\t 1.ENQUEUE\n\t 2.DEQUEUE\n\t 3.DISPLAY\n\t 4.EXIT *** Enter the choice: ");
        scanf("%d", &choice);    
        switch(choice){
            case 1:{
                enqueue();
                break;
            }

            case 2:{
                dequeue();
                break;
            }

            case 3:{
                display();
                break;
            }

            case 4:{
                printf("Exit");
                break;
            }

            default:{
                printf("Enter a valid option: ");
                break;
            }                                                 
        }
    }

    while(choice!=4);
    return 0;
} // end of main()

void enqueue(){ // add elements to the queue
    if(rear>=n-1){
        printf("Queue is full");
    }

    else{
        printf("Enter the value to be enqueued: ");
        scanf("%d",&value);
        rear++;
        q[rear]=value;
    }
}

void dequeue(){   // remove elements from the queue
    if(rear<0){
        printf("Queue is empty");
    }

    else{
        printf("The value to be dequeued is: %d", q[front]);
        front++;
    }
}

void display(){          // display the queue
    if(rear>front){
        for(i=front;i<=rear;i++){
            printf("%d ",q[i]);
        }
    }
    else{
        printf("Queue is empty");
    }
}
