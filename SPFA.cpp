//使用队列的bellman-ford
//用静态邻接表的版本 
#include<iostream>
#include<queue>
const int INF = 100000000;
const int maxn =5000;
using namespace std;
int dist[maxn],vis[maxn],head[maxn];//每个结点第一条出边的索引
int num,n,m,s,cnt[maxn];//入列次数
struct edge{
    int next,to,dis;
}edges[maxn];
void add(int u,int v,int w){
    edges[++num].next = head[u];//记录下一条出边的索引，按记录顺序而言则是前一条出边的索引
    edges[num].to = v;
    edges[num].dis = w;
    head[u] = num;//更新第一条出边的索引
}
void spfa(){
    queue<int>q;
    for (int i = 1; i <= n; i++){//初始化
        dist[i] = INF;
        vis[i] = 0;
    }
    q.push(s);dist[s]=0;vis[s]=1;cnt[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();vis[u]=0;
        for (int i = head[u]; i ; i=edges[i].next){//当i为0则遍历完所有与u相连的邻接结点，结束循环
            int v=edges[i].to;
            if(dist[v]>edges[i].dis+dist[u]){
                dist[v]=edges[i].dis+dist[u]; 
                if(vis[v]){//把松弛后没入队节点的入队
                vis[v]=1;q.push(v);cnt[v]++;
                if(cnt[v]>n)printf("false\n");return;//入列次数超过n说明存在负权环
                }
            }    
        }  
    } 
}
//////////////////////////////////////////////////////////////////////////////////////////
//不熟悉邻接表也可用vector代替 不需要手动管理next指针
vector<pair<int, int>> graph[maxn];  // graph[u] 存储所有与u相连的节点和权重
void addedge(int from, int to, int dis) {
    graph[from].push_back({to, dis});  // 添加到from节点的边
}
void spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
        vis[i] = 0;
    }
    q.push(s);
    dist[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();vis[u] = 0;
        for (auto &edge : graph[u]) {  // 遍历所有邻接节点
            int v = edge.first;   // 目标节点
            int weight = edge.second;  // 边的权重
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    cin>>n>>m>>s;
    for (int i = 0; i < m; i++){
        int f,g,w;
        cin>>f>>g>>w;
        add(f,g,w); 
    }
    spfa();
    for(int i=1; i<=n; i++)
    if(s==i) cout<<0<<" ";
    else cout<<dist[i]<<" "; 
  return 0;
}
//高效的输入
/*inline int read()
{
    int x=0,k=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*k;
}
