//基于动态规划 Bellman其实就是动规的发明者 暴力松弛
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 510
int n,m,k;
int dist[N],last[N]; 
struct edge{
    int u,v,w;
}edges[N];

void bellman_ford(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;//s是起点
    for (int i = 0; i < k; i++){//迭代次数表示路径不能超过k条边
        memcpy(last, dist, sizeof dist);//在限制边数的问题中避免串联即第二个循环内部发生迭代
        for (int j = 0; j < m; j++){
            int u=edges[j].u,v=edges[j].v,w=edges[j].w;
            if(dist[v]>w+last[u])dist[v]=w+last[u];   
        }
    }
    for (int j = 0; j < m; j++){//若还能松弛边则存在负权环
            int u=edges[j].u,v=edges[j].v,w=edges[j].w;
            if(dist[v]>w+last[u])printf("false\n");   
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for (int i = 0; i < m; i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        edges[i].u=u;
        edges[i].v=v;
        edges[i].w=w;
    }
    bellman_ford();
    printf("%d",dist[n]);
}
