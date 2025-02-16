//Dijkstra + 优先队列 链式前向星存储
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int n,m,s,u,v,w,num;
bool book[100000];
const int inf=21474836;
int to[500000],val[500000],head[500000],nex[500000];
long long dis[1000000];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void add(int u,int v,int w){
    nex[++num] = head[u];//记录下一条出边的索引，按记录顺序而言则是前一条出边的索引
    to[num] = v;
    val[num] = w;
    head[u] = num;//更新第一条出边的索引
}
int main(){
    cin>>n>>m>>s;
    for (int i = 1; i <= m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    for (int i = 0; i < n; i++)
        dis[i] = inf;
    dis[s] = 0;
    q.push(make_pair(0,s));
    while(q.size()){
        int x = q.top().second;
        q.pop();
        if(book[x])continue;
        book[x]=1;
        for (int i = head[x]; i; i = nex[x]){
            if(dis[to[i]]>dis[x]+val[i]&&!book[to[i]])
			{
				dis[to[i]]=dis[x]+val[i];
				q.push(make_pair(dis[to[i]],to[i])); 
			}
        }
    }
    for (int i = 1; i <=n; i++){
        cout<<dis[i]<<" ";
    }
}