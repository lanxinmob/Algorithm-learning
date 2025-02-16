//舞狮 Dijkstra
//不AC也是一种善良的方法 这是大佬
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
using ll = long long;
const int inf = 1e9;

struct node
{
    int x,w;
    bool operator<(const node &i)const{
        return w>i.w;}//重载 小根堆
};

void solve(){
    int n;cin>>n;
    vector<vector<int>>a((n+1),vector<int>(n+1));
    vector<vector<node>>g((n+1)*(n+1)*2);
    vector<int>d((n+1)*(n+1)*2);
    vector<bool>vis((n+1)*(n+1)*2);

    auto ge=[&](int x,int y,int k)->int{
        return  (x-1)*n+y+(k?n*n:0); //把偶数和奇数区分开当成两个节点，这里计算节点索引
    }; 

    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)cin>>a[i][j],a[i][j]=(a[i][j]&1)?1:0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {   //向下移动
        if(a[i][j]==1&&a[i+1][j]==1&&i+1<=n)g[ge(i,j,0)].push_back({ge(i+1,j,0),0});
        if(a[i][j]==1&&a[i+1][j]==0&&i+1<=n)g[ge(i,j,0)].push_back({ge(i+1,j,1),1});
        if(a[i][j]==0&&a[i+1][j]==1&&i+1<=n)g[ge(i,j,1)].push_back({ge(i+1,j,0),0});
        if(a[i][j]==0&&a[i+1][j]==0&&i+1<=n)g[ge(i,j,1)].push_back({ge(i+1,j,1),1});
        //向右移动
        if(a[i][j]==1&&a[i][j+1]==1&&j+1<=n)g[ge(i,j,0)].push_back({ge(i,j+1,0),0});
        if(a[i][j]==0&&a[i][j+1]==0&&j+1<=n)g[ge(i,j,1)].push_back({ge(i,j+1,0),0});
    }
    if(a[1][1]&1)g[0].push_back({ge(1,1,0),0});
    g[0].push_back({ge(1,1,1),1});
    
    auto Dijkstra=[&](int t)->void{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)d[ge(i,j,0)]=d[ge(i,j,1)]=inf;
    priority_queue<node>q;
    q.push({0,d[0]=0});
    while(q.size()){
        auto t1=q.top();q.pop();
        if(vis[t1.x])continue;
        vis[t1.x]=true;
        for(const auto &t2:g[t1.x]){
            if(d[t1.x]+t2.w<d[t2.x])
            q.push({t2.x,d[t2.x] = d[t1.x]+t2.w});
        }
    }
};
    Dijkstra(0);
    if(d[ge(n,n,1)]!=inf||d[ge(n,n,0)]!=inf)
    cout<<n*min(d[ge(n,n,0)],d[ge(n,n,1)])<<"\n"; //因为要付就要付一整行所以乘n
    else cout<<"NO!"<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}