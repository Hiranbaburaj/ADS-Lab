#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *l,*r;
}Node;

Node *root=NULL;

Node* insert(Node *node, int val){
    Node *temp;
    if(node==NULL){
        temp=(Node*)malloc(sizeof(Node));
        temp->data=val;
        temp->l=temp->r=NULL;
        node=temp;
        return node;
    }

    if(val <(node->data))
        node->l=insert(node->l,val);
    else
        node->r=insert(node->r,val);
    return node;
}

void inorder(Node *node){
    if (node==NULL)
        return;

    inorder(node->l);
    printf("%d ",node->data);
    inorder(node->r);
}

void preorder(Node *node){
    if (node==NULL)
        return;

    printf("%d ",node->data);
    preorder(node->l);
    preorder(node->r);
}

void postorder(Node *node){
    if (node==NULL)
        return;

    postorder(node->l);
    postorder(node->r);
    printf("%d ",node->data);
}

Node* inords(Node* node){
    if (node==NULL)
        return NULL;
    if(node->l!=NULL){
        return(inords(node->l));
    }    
    return node;
}

Node* delete(Node *node, int val){

    Node *temp;

    if (node==NULL)
        return NULL;
    
    if(val<(node->data))
        node->l=delete(node->l,val);

    else if(val>(node->data))
        node->r=delete(node->r,val);

    else{
        if((node->l==NULL)&&(node->r==NULL)){
            free(node);
            return NULL;
        }

        else if((node->l==NULL)||(node->r==NULL)){

            if(node->l!=NULL){
                temp=node->l;
            }
            else{
                temp=node->r;
            }
            free(node);
            return temp;
        }

        else{
            temp=inords(node->r);
            node->data=temp->data;
            node->r=delete(node->r,temp->data);
        }
    }

}

Node* search(Node *node, int val){
    Node  *temp;
    temp = node;
    if(temp==NULL)
        printf("Value not present");
    
    else{
        if(temp->data==val){
            printf("Value Present in BST");
            return temp;}
        else{
            if(val<(temp->data))
                search(temp->l,val);
            else
                search(temp->r,val);
        }
    }
    return temp;
}

int main(){
    int choice,value;
    do{
        printf("\n1.Insert");
        printf("\n2.Inorder Traversal");
        printf("\n3.Preorder Traversal");
        printf("\n4.Postorder Traversal");
        printf("\n5.Delete");
        printf("\n6.Search");
        printf("\n0.Exit");
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){

            case 1:
                printf("\nEnter the Value to insert to BST: ");
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
                if(root==NULL)
                    printf("\nBST is empty\n");

                else
                    {printf("\nEnter the Value to be Deleted: ");
                    scanf("%d",&value);
                    root=delete(root,value);}
                break;            

            case 6:
                if(root==NULL)
                    printf("\nBST is empty\n");

                else
                    {printf("\nEnter the Value to search: ");
                    scanf("%d",&value);
                    root=search(root,value);}
                break;            

            case 0:
                printf("Exit");
                break;

            default:
                printf("\nInvalid option. Try again!!!\n");
                break;
        }
    }
    while(choice!=0);
    return 0;
}
