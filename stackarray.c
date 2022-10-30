#include <stdio.h>
int stack[100],n,i,top,x,c;

void push(void);
void pop(void);
void display(void);

int main(){
    top=-1;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    do {

    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT *** Enter the choice");
    scanf("%d", &c);    
    switch(c)
    {
        case 1:{
            push();
            break;
        }

        case 2:{
            pop();
            break;
        }

        case 3:{
            display();
            break;
        }

        case 4:{
            printf("Exit ");
            break;
        }

        default:{
            printf("Please Enter a Valid Choice(1/2/3/4)");
            break;
        }
    }
    } //end of do 
    while(c!=4);
    return 0;
}

void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");
        
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}

void  pop(){        //pop- function
    if (top <= -1){
        printf("Stack is Underflow");
    }
    else{
        printf("value to be popped: %d",stack[top]);
        top--;
    }
}    

void display(){
    if(top>-1){
    for(i=top;i>=0;i--)
    printf("%d",stack[i]);}
    else{
        printf("Stack is empty");
    }
}
