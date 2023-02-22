#include<stdio.h>

int main(){
    int m[6][6] = {{0,4,4,0,0,0},
        {4,0,2,0,0,0},
        {4,2,0,3,6,1},
        {0,0,3,0,2,0},
        {0,0,6,2,0,3},
        {0,0,1,0,3,0}}; 

    int i,j,pred[6]={0},distance[6],startnode=0,nextnode,mindistance,visited[6]={0},count=1;

    for(i=0;i<6;i++)
        for(j=0;j<6;j++)
            if(m[i][j]==0)
                m[i][j]=999;

    for(i=0;i<6;i++){
        distance[i]=m[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
        
    while(count<6){
        mindistance=999;
        for(i=0;i<6;i++)
            for(j=0;j<6;j++)
                if((distance[i]<mindistance)&&(visited[i]==0)){
                    mindistance=distance[i];
                    nextnode=i;
                }
                visited[nextnode]=1;
        for(i=0;i<6;i++){
            if(visited[i]==0){
                if(mindistance+m[nextnode][i]<distance[i]){
                    distance[i]=mindistance+m[nextnode][i];
                    pred[i]=nextnode;
                }
            }
        }
        count++;
    }
    for(i=0;i<6;i++)
        if(i!=startnode){
            printf("\n\nMin. distance to %d = %d\n",i,distance[i]);
            printf("%d ",i);
            j=i;
            do{
                j=pred[j];
                printf(" <- %d ",j);
            }while(j!=startnode);
        }
}
