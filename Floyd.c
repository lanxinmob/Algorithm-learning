#include<stdio.h>
#include<stdlib.h>
#define max 10000 

int n;//顶点数
int matrix[max][max];//邻接矩阵
int path[max][max];
int dist[max][max];

void floyd(int v,int w){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dist[i][j] = matrix[i][j];//初始化两个矩阵
            path[i][j] = j;
        }
    }
    for (int k = 0; k < n; k++){//k是中间点
        for (int i = 0; i < n; i++){//i是源点
            for (int j = 0; j < n; j++){//j是终点
            if (dist[i][j] > dist[i][k]+dist[k][j]){
                dist[i][j] = dist[i][k]+dist[k][j];//松弛 更新最短路径
                path[i][j] = path[i][k];//更新第一个中间节点
            }
        }
    }
}   for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d",dist[i][j]);  
        }
    printf("\n");    
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d",path[i][j]);  
        }
    printf("\n");    
    }
    int k = path[v][w];
    printf("%d",v);//输出起点
    while (k!=w){
        printf(" %d",k);
        k = path[k][w];
    }
    printf(" %d\n",w);//输出终点
}
int main(){
    int v,w;
    scanf("%d %d %d",&n,&v,&w);
    for (int i = 0; i < n; i++){
        for (int j= 0; j < n; j++){
            scanf("%d",matrix[i][j]);
        }
    }
    floyd(v,w);
    return 0;
}