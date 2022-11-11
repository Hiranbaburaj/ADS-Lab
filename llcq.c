//circular queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct node node;
node *head;
node *rear;

void enqueue(){
    node *temp, *t2;
    int data;
    printf("Enter the data you want to enter at the end: ");
    scanf("%d",&data);
    temp=(node*)malloc(sizeof(node));
    temp->value=data;

    if((head == NULL)&&(rear == NULL)){
        head=rear=temp;
        rear->next=head;
    }

    else{
	rear->next=temp;
	rear=temp;
	rear->next=head;
    }
}

void dequeue(){
    if(head==NULL){
        printf("Linked List is empty");
    }
    else if(head->next==head){
        printf("%d is deleted",head->value); 
        head=NULL;  
	rear=NULL;     
    }      
    else{
    node *temp;
    printf("%d is deleted",head->value);
    temp=head->next;
    rear->next=temp;
    head=temp;

    }
}

void display(){
    node*temp=head;
    if((head == NULL)&&(rear == NULL)){
	printf("Queue Is Empty");
	}
else{	
	do
    {
        printf("%d ",temp->value);
        temp=temp->next;
    }
	while(temp!=rear->next);

}
}
void peek(){
	printf("%d",head->value);
}

int main(){
    int choice;
    do{
        printf("\nEnter the Choice\n 1.Enqueue\n 2.Dequeue\n ");
        printf("3.Display the front element\n 4.Display the entire queue");
        printf("\n 0.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            		case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
                              
                        case 0:
				printf("Exit");
				break;
			deault:
				printf("Invalid option ! Try Again..");
        }
    }
    while(choice!=0);
    return 0;

}
