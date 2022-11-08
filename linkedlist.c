#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;  
};

typedef struct node node;
node *head;

void insertend(){
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

void insertfr(){
    node *temp;
    int data;
    printf("Enter the data you want to enter at front: ");
    scanf("%d",&data);
    temp=(node*)malloc(sizeof(node));
    temp->value=data; 

    if(head == NULL){
        head=temp;
        head->next=NULL;
    }

    else{
        temp->next=head;
        head=temp;
    }       
}

void insertpos(){
    node *temp, *t2;
    int data,pos,p2=2;
    printf("Enter at which position you want to enter the data: ");
    scanf("%d",&pos);
    printf("Enter the data you want to enter at the specified position: ");
    scanf("%d",&data); 
    temp=(node*)malloc(sizeof(node));
    temp->value=data;
    if(head == NULL){
        printf("The linked list is Empty");
    }           

    else if(pos==1){
        temp->next=head;
        head=temp;
    }

    else{
        t2=head;
        while(t2->next!=NULL){
            if(pos==p2){
                temp->next=t2->next;
                t2->next=temp;
                break;
            }
            else{
                t2=t2->next;
                p2++;
                
            }
        }
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
        printf("\nEnter a Value: ");
        scanf("%d",&choice);
        switch(choice){
        case 0:{            //exit
            printf("Exit");
            break;        }
        case 1:{            //insert node in the end of LL
            insertend();
            break;        }
        case 2:{            //insert node in the front of LL
            insertfr();
            break;        }   
        case 3:{
            insertpos();
            break;        }         
        case 4:{            //displays the LL
            display();
            break;        } 
        default:            //default
			printf("Invalid option ! Try Again..");                   
        }
    }
    while(choice!=0);
    return 0;
}


