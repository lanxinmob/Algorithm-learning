//Floyd
#include<stdio.h>
#include<limits.h>

void floyd(){
    memset(dist,0x3f,sizeof dist);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dist[i][j] = matrix[i][j];//初始化矩阵
        }
        dist[i][i]=0;
    }
    for (int i = 0; i < n; i++){
        for (int k = 0; k < n; k++){
            for (itn j = k+1; j < n; j++){//对无向图的优化
                if(dist[k][j]>dist[k][i]+dist[i][j])dist[k][j]=dist[k][i]+dist[i][j];
                dist[j][k] = dist[k][j];
            }
        }
    }
    int min=INT_MAX;
    int res=-1;
    int *pathnum=(int*)calloc(n,sizeof int);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(dist[i][j]<=threshold)pathnum[i]++;//要求在阈值内路径数量最少而编号最大的
        }
        if(pathnum[i]<min)min=pathnum[i],res=i;
    }
}    
int main(){

}

