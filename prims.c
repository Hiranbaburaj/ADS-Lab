#include<stdio.h>
#define V 20

int main(){

    int costmatrix[V][V];
    int visited[V]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int i,j;
    int vert;
    int edge;
    int row,col;
    int count=1;
    int mincost,totalcost=0;

    printf("Enter the no. of vertices: ");
    scanf("%d",&vert);

    printf("\nEnter the Cost matrix\n");

    for(i=1; i<=vert; i++)
        for(j=1; j<=vert; j++){
            scanf("%d",&costmatrix[i][j]);
                if(costmatrix[i][j]==0)
                    costmatrix[i][j]=999;
        }

    /*for(i=1; i<=vert; i++){        
        printf("\n");
        for(j=1; j<=vert; j++){
            printf("%d ",costmatrix[i][j]);
        } 
    }*/       

    visited[1]=1;

    while(count < vert){
        for(i=1, mincost=999; i<=vert; i++){
            for(j=1; j<=vert; j++){
                if(costmatrix[i][j] < mincost){

                    if(visited[i]!=0){

                        mincost=costmatrix[i][j];
                        row=i;
                        col=j;
                    }
                }
            }
        }

        if((visited[row] == 0) || (visited[col] == 0)){
            printf("\n%d -> %d = %d",row,col,mincost);
            count++;
            totalcost = totalcost + mincost;
            visited[col]=1;

        }

        costmatrix[row][col] = costmatrix[col][row] = 999;

    }

    printf("\nThe total min cost is: %d",totalcost);
    return 0;
}
