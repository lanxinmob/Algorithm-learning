//Dijkstra的直接运用 得出最短路并输出经过的结点（DFS）
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int matrix[2505][2505];
int dist[2505];
int book[2505];
int pre[2505];
int n,m,s,t,u,v,w;

void Dijkstra(){
    int k,min;
    for(int i = 1;i<=n;i++){
        dist[i]=matrix[s][i];
        pre[i] = s;
    }
    book[s]=1;
    dist[s]=0;
    for (int i = 1; i <= n; i++)
    {   min = INT_MAX;
        for (int j = 1; j <= n; j++)
        {
            if (!book[j]&&min>dist[j])
            {
                min = dist[j];
                k = j;
            }
        }
        book[k] = 1;
        if(k==t)break;//提前终止
        for (int j = 1; j <= n; j++)
        {   
            if (!book[j]&&dist[j]>min+matrix[k][j])
            {
                dist[j] = min+matrix[k][j];
                pre[j] = k;
            }   
        }
    }
}
void dfs(int start,int end){
    if(start==end){
    printf("%d",end);
    return;
    }
    dfs(start,pre[end]);
    printf(" %d",end);
}
int main(){
    scanf("%d %d %d %d",&n,&m,&s,&t);
    memset(matrix,0x3f,sizeof matrix);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        matrix[v][u] = matrix[u][v]=w;
    }
    Dijkstra();
    dfs(s,t);
    printf("%d",dist[t]);
    return 0;
}