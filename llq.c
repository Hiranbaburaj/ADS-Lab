//queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct node node;
node *head;

void enqueue(){
    node *temp, *t2;
    int data;
    printf("Enter the data you want to enter at the end: ");
    scanf("%d",&data);
    temp=(node*)malloc(sizeof(node));
    temp->value=data;

    if(head == NULL){
        head=temp;
        head->next=NULL;
    }

    else{
        t2=head;
        while(t2->next!=NULL){
            t2=t2->next;
        }
        t2->next=temp;
        temp->next=NULL;
    }
}

void dequeue(){
    if(head==NULL){
        printf("Queue is empty");
    }
    else if(head->next==NULL){
        node *temp;
        temp=head;
        printf("%d is deleted",head->value); 
        head=NULL;
        free(temp);
    }      
    else{
    node *temp;
    printf("%d is deleted",head->value);
    temp=head;
    head=head->next;
    free(temp);
    }
}

void display(){
    node*temp=head;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
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

			default:
				printf("Invalid option ! Try Again..");
        }
    }
    while(choice!=0);
    return 0;

}
