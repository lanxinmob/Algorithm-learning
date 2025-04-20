//网络稳定性 
//krusukal最大生成树 dfs暴力
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10,M=3e5+10;
int n,m,p,min_value;
typedef pair<int,int>pi;
vector<pi>g[M];
int fa[N];
struct node
{
    int u,v,w;
}a[N];
int find(int x){
    if(x!=fa[x])fa[x] = find(fa[x]);
    return fa[x];
}
void krus(){
     sort(a,a+m,[&](node x,node y){return x.w>y.w;});
     for(int i=0;i<n;i++){
        fa[i] = i;
    }
    for(int i=0;i<m;i++){
        int x = find(a[i].u);
        int y = find(a[i].v);
        if(x==y)continue;
        fa[x] = y;
        g[x].push_back({y,a[i].w});
        g[y].push_back({x,a[i].w});
    }
}
void dfs(int u,int v,int w,int m){
    if(u==v){
        min_value = m;
        return;
    }
    for(auto& a:g[u]){
       if(a.first!=w||w==-1){
        dfs(a.first,v,u,min(m,a.second));
       }
    }
}
void solve(){
    int x,y;
    cin>>x>>y;
    min_value = INT_MAX;
    dfs(x,y,-1,INT_MAX);
    if(min_value==INT_MAX)cout<<-1<<"\n";
    else cout<<min_value<<"\n";
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>p;
    for(int i=0;i<m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    krus();
    while(p--)solve();
    return 0;
}
//krusukal最大生成树 dfs 倍增lca
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10,M=3e5+10;
const int inf = 0x3f3f3f3f;
int n,a[N],cnt,lmin[N],lmax[N],rmin[N],rmax[N];
int ls[N],rs[N];
int ltre[1<<22][3],rtre[1<<22][3];
void add(int x,int tre[][3]){
	int p = 0;
	 for(int i=20;i>=0;i--){
	 int u= x>>i&1;
	 if(!tre[p][u])tre[p][u] = ++cnt;
	 p = tre[p][u];
	 }
}
int query_min(int x,int tre[][3]){
	int p=0,res=0;
	for(int i=20;i>=0;i--){
		int u=x>>i&1;
		if(tre[p][u]){
			p = tre[p][u];
		}else {
			p= tre[p][!u];
      res += 1<<i;
		}
	}return res;
}
int query_max(int x,int tre[][3]){
	int p=0,res=0;
	for(int i=20;i>=0;i--){
		int u=x>>i&1;
		if(tre[p][!u]){
			p = tre[p][!u];
			res+= 1<<i;
		}else {
			p= tre[p][u];
		}
	}return res;
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    for(int i=0;i<=n+1;i++){
    	lmin[i] = rmin[i] = inf;
    	rmax[i] = lmax[i] = 0;
    }
    add(0,ltre);
    for(int i=1;i<=n;i++){
    	ls[i] = ls[i-1]^a[i];
    	lmax[i] = max(lmax[i-1],query_max(ls[i],ltre));
    	lmin[i] = min(lmin[i-1],query_min(ls[i],ltre));
    	add(ls[i],ltre);
    }
    cnt =0;
    add(0,rtre);
    for(int i=n;i>=1;i--){
    	rs[i] = rs[i+1]^a[i];
    	rmax[i] = max(rmax[i+1],query_max(rs[i],rtre));
    	rmin[i] = min(rmin[i+1],query_min(rs[i],rtre));
    	add(rs[i],rtre);
    }
    int ans=0;
    for(int i=1;i<=n-1;i++){
    	ans = max(ans,max(rmax[i+1]-lmin[i],lmax[i]-rmin[i+1]));
    }cout<<ans;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int p=1;
    while(p--)solve();
    return 0;
}