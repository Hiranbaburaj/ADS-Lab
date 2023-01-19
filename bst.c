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
            preorder(rt->l);
        }
        
        if(rt->r!=NULL){
            preorder(rt->r);
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
            postorder(rt->l);
        }
        
        if(rt->r!=NULL){
            postorder(rt->r);
        }
        printf("%d ",rt->value);
    }
}

int search(node *rt,int dt){
    while(rt!=NULL){
        if((rt->value)==dt){
            return 1;
            break;
        }
        else if(dt > (rt->value)){
            rt=rt->r;
        }
        else{
            rt=rt->l;
        }
    }
    return 0;
}

int delete(node *rt,node *prev){
    if(((rt->l)==0) && ((rt->l)==0)){
        prev->l=NULL;
        prev->r=NULL;
    }
}

int del(node *rt,int dt){
    node *prev;
    while(rt!=NULL){
        if((rt->value)==dt){
            delete(rt,prev);
            return 1;
            break;
        }
        else if(dt > (rt->value)){
            prev=rt;
            rt=rt->r;
        }
        else{
            prev=rt;
            rt=rt->l;
        }
    }
    return 0;
}  


void main(){
    int ch,sr;
    do{
        printf("\nEnter the choice: ");
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

            case 5:
                if(root==NULL){
                    printf("BST is Empty");
                }

                else{
                    int data;
                    printf("Enter the data you want to search: ");
                    scanf("%d",&data);
                    sr=search(root,data);
                    if(sr==1){
                        printf("\nValue present in bst\n");
                    }
                    else{
                        printf("\nValue not present\n");
                    }
                }
                break;

            case 6:
                if(root==NULL){
                    printf("BST is Empty");
                }

                else{
                    int data;
                    printf("Enter the data you want to delete: ");
                    scanf("%d",&data);
                    sr=del(root,data);
                    if(sr==1){
                        printf("\nValue deleted\n");
                    } 
                    else{
                        printf("\nValue Not present\n");
                    }                   
                }
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
