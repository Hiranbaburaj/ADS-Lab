//stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct node node;
node *head;

void push(){
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

void pop(){
    if(head==NULL){
        printf("Linked List is empty");
    }
    else if(head->next==NULL){
        printf("%d is deleted",head->value);
        node *temp;
        temp=head;
        head=NULL;
        free(temp);
    } 
    else{
        node *temp , *t2;
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        printf("%d is deleted",temp->next->value);
        t2=temp->next;
        temp->next=NULL;
        free(t2);
    }   
}

void peek(){
    node*temp=head;
    while(temp!=NULL){
	if(temp->next==NULL){
        printf("%d ",temp->value);}
        temp=temp->next;
    }
}

void display(){
    node*temp=head;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
}

int main(){
    int choice;
    do{
        printf("\nEnter the Choice\n 1.Push\n 2.Pop\n ");
        printf("3.Peek\n 4.Display");
        printf("\n 0.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            		case 1:
				push();
				break;
			case 2:
				pop();
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
