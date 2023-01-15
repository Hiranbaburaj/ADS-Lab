//bst
#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node *l;
    struct node *r;
}*root=NULL,*temp=NULL;

typedef struct node node;

void insert(){
    int data;
    node *newnode , *prev;
    printf("Enter the data you want to enter: ");
    scanf("%d",&data);    
    newnode=(node*)malloc(sizeof(node));
    newnode->value=data;
    newnode->l=NULL;
    newnode->r=NULL;

    if(root == NULL){
        root=newnode;
    }

    else{
        temp=root;
        while(temp!=NULL){
            prev=temp;
            if(data>(temp->value)){
                temp=temp->r;
            }
            else{
                temp=temp->l;
            }
        }

        if(data>(prev->value)){
            prev->r=newnode;
        }
        else{
            prev->l=newnode;
        }       
    }
}

void inorder(node *rt){
    if(rt==NULL){
        printf("BST is Empty");
        return;
    }
    else{
        if(rt->l!=NULL){
            inorder(rt->l);
        }
        printf("%d ",rt->value);
        if(rt->r!=NULL){
            inorder(rt->r);
        }
    }
}

void preorder(node *rt){
    if(rt==NULL){
        printf("BST is Empty");
        return;
    }
    else{
        printf("%d ",rt->value);
        if(rt->l!=NULL){
            inorder(rt->l);
        }
        
        if(rt->r!=NULL){
            inorder(rt->r);
        }
    }
}

void postorder(node *rt){
    if(rt==NULL){
        printf("BST is Empty");
        return;
    }
    else{
        if(rt->l!=NULL){
            inorder(rt->l);
        }
        
        if(rt->r!=NULL){
            inorder(rt->r);
        }
        printf("%d ",rt->value);
    }
}

void main(){
    int ch;
    do{
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;   
            case 4:
                postorder(root);
                break;               
            case 0:
                printf("Exit");
                break;
            default:
                printf("Invalid choice");
        }
    }
    while(ch!=0);
}
