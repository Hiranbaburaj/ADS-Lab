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
    printf("Enter the value to insert at the beginning: ");
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
    node *temp,*t2;
    int data,pos,count=2;
    printf("Enter the position to insert data: ");
    scanf("%d",&pos);    
    printf("Enter the value to insert at a given position: ");
    scanf("%d",&data);
    temp=(node*)malloc(sizeof(node));
    temp->value=data;  
    if(head==NULL){
    printf("Linked list is Empty");        
    }   

    else if(pos==1){
        temp->next=head;
        head=temp;        
    }
    
    else{
        t2=head;
        while(t2->next!=NULL){
            if(pos==count){
                temp->next=t2->next;
                t2->next=temp;
                break;
            }
            else{
                t2=t2->next;
                count++;
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

void search(){
    node *temp;
    int data;
    printf("Enter the value to Search: ");
    scanf("%d",&data);  
    temp=head;
    while(temp!=NULL){
        if(temp->value==data){
            printf("Value present in linked list\n");
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Value not found\n");
    }  
}

void del(){
    node *temp,*t2;
    int pos,count=2;
    printf("Enter the position of the node you want to delete: ");  
    scanf("%d",&pos);
    temp=head;
    t2=head->next;
    if(pos==1){
        delf();  
    }

    if(pos==2){
        printf("%d is deleted",t2->value);
        head->next=t2->next;

    }
    else{
        while(pos!=count){
            temp=temp->next;
            t2=t2->next;
            count++;
        }
        printf("%d is deleted",temp->value);
        temp->next=t2->next;
    }
}

void delf(){
    if(head==NULL){
        printf("Linked List is empty");
    }
    else if(head->next==NULL){
        printf("%d is deleted",head->value); 
        head=NULL;       
    }      
    else{
    node *temp;
    printf("%d is deleted",head->value);
    temp=head->next;
    head=temp;
    }
}

void delend(){
    if(head==NULL){
        printf("Linked List is empty");
    }
    else if(head->next==NULL){
        printf("%d is deleted",head->value); 
        head=NULL;       
    } 
    else{
        node *temp;
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        printf("%d is deleted",temp->next->value);
        temp->next=NULL;
    }   
}
int main(){
    int choice;
    do{
        printf("\nEnter the Choice\n 1.Insert at the end\n 2.Insert at the beginning\n ");
        printf("3.Insert at a given Position\n 4.Display the the Linked List\n ");
        printf("5.Check whether the given element is present \n 6.Delete node from a position\n ");
        printf("7.Delete node at the beginning\n 8.Delete node from the end\n 0.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            		case 1:
				insertend();
				break;
			case 2:
				insertfr();
				break;
			case 3:
				insertpos();
				break;
			case 4:
				display();
				break;
			case 5:
				search();
				break;
			case 6:
				del();
				break; 
			case 7:
				delf();
				break;   
			case 8:
				delend();
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
