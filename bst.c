#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *l, *r;    
};

typedef struct node node;

node* insert(node *nod,int val){
    node *temp;
    if (nod==NULL){
        temp=(node*)malloc(sizeof(node));
        temp->data=val;
        temp->l=NULL;
        temp->r=NULL;
        nod=temp;
        return nod;
    }

    if (val < (nod->data)){
        nod->l=insert(nod->l,val);
    }
    else{
        nod->r=insert(nod->r,val);
    }
    return nod;
}

void inorder(node *nod){
    if(nod==NULL){
        return;
    }
    inorder(nod->l);
    printf("%d ",nod->data);
    inorder(nod->r);
}

void preorder(node *nod){
    if(nod==NULL){
        return;
    }
    printf("%d ",nod->data);    
    preorder(nod->l);
    preorder(nod->r);
}

void postorder(node *nod){
    if(nod==NULL){
        return;
    }
    postorder(nod->l);
    postorder(nod->r);
    printf("%d ",nod->data);
}

node* inords(node *nod){
    if(nod==NULL)return NULL;
    if(nod->l!=NULL){
        return(inords(nod->l));
    }
    return nod;
}

node* delete(node *nod,int val){
    node *temp;
    if(nod==NULL)return NULL;
    if (val < (nod->data)){
        nod->l=delete(nod->l,val);
    }
    else if (val > (nod->data)){
        nod->r=delete(nod->r,val);
    }
    else{
        if((nod->l==NULL)&&(nod->r==NULL)){
            free(nod);
            return NULL;
        }
        else if((nod->l==NULL)||(nod->r==NULL)){
            if(nod->l!=NULL){
                temp=nod->l;
            }
            else{
                temp=nod->r;
            }
            free(nod);
            return temp;
        }
        else{
            temp=inords(nod->r);
            nod->data=temp->data;
            nod->r=delete(nod->r,temp->data);
        }
    }
    return nod;
}

int main(){
    node *root=NULL;
    int choice;
    int value;
    do{
        printf("\nEnter the Choice\n1.Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Delete\n0.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the Value to insert: ");
            scanf("%d",&value);
            root=insert(root,value);
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
            printf("\nEnter the Value to delete: ");
            scanf("%d",&value);
            root=delete(root,value);
            break;

        default:
            break;
        }
    }
    while(choice!=0);
    return 0;
}
