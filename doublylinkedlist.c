#include <stdio.h>
#include <stdlib.h>

int  size=0;

struct node{
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node node;
node *head;
node *rear;

void insertend(){
    node *temp ;
    int data;
    printf("Enter the data you want to enter at the end: ");
    scanf("%d",&data);
    temp=(node*)malloc(sizeof(node));
    temp->value=data;

    if(head == NULL){
        head=temp;
        head->next=NULL;
        head->prev=NULL;
        size++;
    }

    else if(head->next == NULL){
        rear=temp;
        head->next=rear;
        rear->prev=head;
        rear->next=NULL;
        size++;
    }

    else{
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
        rear->next=NULL;
        size++;
    }
}

void insertfr(){
    node *temp;
    int data;
    printf("Enter the data you want to enter at the front: ");
    scanf("%d",&data);
    temp=(node*)malloc(sizeof(node));
    temp->value=data;

    if((head == NULL)&&(rear == NULL)){
        head=temp;
        head->next=NULL;
        head->prev=NULL;
        size++;
    }

    else if(head->next == NULL) {
        temp->next=head;
        temp->prev=NULL;
        head->prev=temp;
        rear=head;
        head=temp;
        size++;
    }

    else{
        temp->next=head;
        temp->prev=NULL;
        head->prev=temp;
        head=temp;
        size++;
    }
}

void insertpos(){

    if((head == NULL)&&(rear == NULL)){
        printf("Linked List is empty");
    }

    else
    {
        node *temp , *t2;
        int data, position , count = 2 ;
        printf("Enter the position you want to enter the data : ");
        scanf("%d",&position);


        if((position>size)||(position<=0)){
        printf("Please Enter a Valid Position \n");
        }

        else{
        printf("Enter the data you want to enter at the given position: ");
        scanf("%d",&data);
        temp=(node*)malloc(sizeof(node));
        temp->value=data;
        if(position==1){
                if(head->next == NULL) {
                temp->next=head;
                temp->prev=NULL;
                head->prev=temp;
                rear=head;
                head=temp;
                size++;
            }

            else{
                temp->next=head;
                temp->prev=NULL;
                head->prev=temp;
                head=temp;
                size++;
            }
        }

        else{
                t2=head;
                while(t2->next!=NULL){
                    if(position==count){
                        if(t2->next!=rear){
                            temp->next=t2->next;
                            (t2->next)->prev=temp;
                            t2->next=temp;
                            temp->prev=t2;
                            size++;
                            break;
                        }
                        else{
                            temp->next=rear;
                            rear->prev=temp;
                            t2->next=temp;
                            temp->prev=t2;
                            size++;
                            break;
                        }
                    }

                    else{
                        t2=t2->next;
                        count++;
                    }
                }
            }
        }
    }
}

void dispf(){
    node*temp=head;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
}

void dispb(){
    node*temp=rear;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->prev;
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

void delf(){
    node *temp;
    if((head == NULL)){
        printf("Linked List is empty");
    }
    
    else if(head->next == NULL){
        printf("%d is Deleted",head->value);
        temp=head;
        head=NULL;
        rear=NULL;
        free(temp);
        size--;
    }

    else{
        printf("%d is Deleted",head->value);
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        size--;
    }
}

void delend(){
    node *temp;
    if(head == NULL){
        printf("Linked List is empty");
    }

    else if(head->next == NULL){
        printf("%d is Deleted",head->value);
        temp=head;
        head=NULL;
        rear=NULL;
        free(temp);
        size--;
    }

    else if(head->next == rear){
        printf("%d is Deleted",rear->value);
        head->next=NULL;
        temp=rear;
        rear=NULL;
        free(temp);
        size--;
    }

    else{
        printf("%d is Deleted",rear->value);
        temp=rear;
        rear=rear->prev;
        rear->next=NULL;
        free(temp);
        size--;
    }
}

void delpos(){
    if(head == NULL){
        printf("Linked List is empty");
    }

    else{
        node *temp , *t2;
        int position , count = 2;
        printf("Enter the position of the data you want to delete : ");
        scanf("%d",&position);
        if((position>size)||(position<=0)){
            printf("Please Enter a Valid Position \n");
        }

        else{
        if (position == 1){
            delf();
        }

        else if (position == 2){
            if(head->next == rear){
                printf("%d is Deleted",rear->value);
                head->next=NULL;
                temp=rear;
                rear=NULL;
                free(temp);
                size--;
            }

            else{
                temp=head->next;
                printf("%d is Deleted",temp->value);
                head->next=temp->next;
                (temp->next)->prev=head;
                free(temp);
                size--;
            }
        }

        else{
            temp = head;
            t2 = head->next;
                while(position!=count){
                    t2=t2->next;
                    temp=temp->next;
                    count++;
                }
                if(t2->next!=NULL){
                    printf("%d is Deleted",t2->value);
                    temp->next=t2->next;
                    (t2->next)->prev=temp;
                    free(t2);
                    size--;
                }

            else{
                printf("%d is Deleted",t2->value);
                temp->next=NULL;
                free(t2);
                size--;
            	}
            }
        }
    }
}

int main(){
    int choice;
    do{
        printf("\nEnter the Choice\n 1.Insert at the end\n 2.Insert at the beginning\n ");
        printf("3.Insert at a given Position\n 4.Display the Linked List in Forward Direction\n 5.Display the Linked List in Reverse Direction\n ");
        printf("6.Check whether the given element is present \n 7.Delete node at the beginning\n ");
        printf("8.Delete node from the end\n 9.Delete node from a position\n 0.Exit\n");
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
				dispf();
				break;
			case 5:
				dispb();
				break;
			case 6:
				search();
				break; 
			case 7:
				delf();
				break;   
			case 8:
				delend();
				break;  
			case 9:
				delpos();
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
