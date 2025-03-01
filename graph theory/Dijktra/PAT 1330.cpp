//Dijkstra + DFS 在相同距离下要求费用最小 
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int matrix[510][510];
int dist[510];
int book[510];
int cost[510][510];
vector<int>pre[510];
vector<int>path,tempath;
int n,m,s,t,u,v,w,d;
int min_cost = INT_MAX;

void Dijkstra(){
    int k,minx;
    //fill(dist, dist+510, INT_MAX);
    for (int i = 0; i < n;i++){
        dist[i] = matrix[s][i];
        pre[i].push_back(s);
    }
    book[s]=1;
    dist[s]=0;
    for (int i = 0; i < n; i++)
    {   minx = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (!book[j]&&minx>dist[j])
            {
                minx = dist[j];
                k = j;
            }
        }
        book[k] = 1;
        if(k==t)break;//提前终止
        for (int j = 0; j < n; j++){   
            if(!book[j] && matrix[k][j] != INT_MAX){//防止溢出
				if(dist[j] > dist[k]+matrix[k][j]){
					dist[j] = dist[k]+matrix[k][j];
					pre[j].clear();
					pre[j].push_back(k);
				}else if(dist[j] == dist[k]+matrix[k][j]){//相同距离也要记录因为需要比较费用
					pre[j].push_back(k);
				} 
			}
		}
    }
}
void dfs(int x){
    tempath.push_back(x);
    if(s==x){
        int tempcost=0;
        for (int i = tempath.size()-1; i>=1; i--)
        {   int d1=tempath[i],d2=tempath[i-1];
            tempcost+=cost[d1][d2];
        }
        if(tempcost<min_cost){
        min_cost=tempcost;
        path=tempath;
        }
        tempath.pop_back();
        return;  
    }
    for (int i = 0; i <pre[x].size(); i++){
        dfs(pre[x][i]);
    }
    tempath.pop_back();
}
int main(){
    scanf("%d %d %d %d",&n,&m,&s,&t);
    fill(matrix[0], matrix[0] + 510 * 510, INT_MAX);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d %d",&u,&v,&w,&d);
        matrix[v][u] = matrix[u][v] = w;
        cost[u][v] = cost[v][u] = d;
    }
    Dijkstra();
    dfs(t);
    for(int i=path.size()-1;i>=0;i--){
        printf("%d ",path[i]);	
    }
    printf("%d %d",dist[t],min_cost);
    return 0;
}