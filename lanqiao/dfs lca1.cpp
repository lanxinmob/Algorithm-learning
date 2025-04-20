//树上前缀和 LCA最近公共祖先 DFS暴力超时
//倍增LCA 但是迭代 修改一下dfs即可 修改后时间复杂度不变 但我们遇到递归太深而爆栈时要知道如何处理
void dfs(int u,int v){
	stack<pi>s;
	s.push({u,v});
	while(!s.empty()){
	int u = s.top().first;
	int v = s.top().second;
	s.pop();
	dep[u] = dep[v]+1;
	stjump[u][0] = v;
	for(int p = 1;(1<<p)<=dep[u];p++){
		stjump[u][p] = stjump[stjump[u][p-1]][p-1];
	}for(auto &e:edge[u]){
		int p = e.first;
		if(p!=v)
		s.push({p,u});
	}
}}
//倍增LCA
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =2e5+10;
int dep[N],stjump[N][20];
int n,k; 
typedef pair<int,int> pi;
vector<pi>edge[N];
int a[N],sum[N];
void dfs(int u,int v){
	dep[u] = dep[v]+1;
	stjump[u][0] = v;
	for(int p = 1;(1<<p)<=dep[u];p++){
		stjump[u][p] = stjump[stjump[u][p-1]][p-1];
	}for(auto &e:edge[u]){
		int p = e.first;
		if(p!=v)
		dfs(p,u);
	}
}
int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	for(int p=19;p>=0;p--){
		if(dep[stjump[a][p]]>=dep[b]){
			a = stjump[a][p];
		}}
		if(a==b)return a;
        for(int p=19;p>=0;p--){
		if(stjump[a][p]!=stjump[b][p]){
			a = stjump[a][p];
			b = stjump[b][p];
		}}
		return stjump[a][0];
}
void cal_sum(int c,int parent){
	for(auto &e:edge[c]){
		int u = e.first;
		if(u==parent)continue;
		sum[u] = sum[c]+e.second;
		cal_sum(u,c);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int x,y,t;
		cin>>x>>y>>t;
		edge[x].push_back({y,t});
		edge[y].push_back({x,t});
	}
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	cal_sum(1,0);
	dfs(1,0);
	int ans=0;
	for(int i=0;i<k-1;i++){
		int u = a[i],v = a[i+1];
		int s = sum[u]+sum[v]-sum[lca(u,v)]*2;
		ans+= s;//先算出这条路线所需的时间再逐个计算不走某点的时间
	}
	for(int i=0;i<k;i++){
		int tem = ans;
		if(i==0){
			tem -= sum[a[i]]+sum[a[i+1]]-sum[lca(a[i],a[i+1])]*2;
		}else if(i==k-1){
			tem -= sum[a[i]]+sum[a[i-1]]-sum[lca(a[i],a[i-1])]*2;
		}else{
			tem -= sum[a[i-1]]+sum[a[i]]-sum[lca(a[i],a[i-1])]*2;
			tem -= sum[a[i]]+sum[a[i+1]]-sum[lca(a[i],a[i+1])]*2;
			tem += sum[a[i-1]]+sum[a[i+1]]-sum[lca(a[i+1],a[i-1])]*2;
		}
		cout<<tem<<" ";
	}
	
}
signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t=1;
  //cin>>t;
  while(t--)solve();
  return 0;
}

/*DFS 暴力
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =2e5+10;

int n,k; 
typedef pair<int,int> pi;
vector<pi>edge[N];
map<pi,int>st;
int a[N];
bool dfs(int u,int c,int fa,int v,int w){//这里是树所以记录父亲就可以如果是图就要有一个st记录是否走过
	if(c==v){
		st[{u,v}] = w;
		st[{v,u}] = w;
		return true;
	}for(int i=0;i<edge[c].size();i++){
	int son = edge[c][i].first;
	if(son == fa)continue;
    if(dfs(u,son,c,v,w+edge[c][i].second)){
       return true;	
    }
	}return false;
}
void solve(){
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int x,y,t;
		cin>>x>>y>>t;
		edge[x].push_back({y,t});
		edge[y].push_back({x,t});
	}
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=0;i<k-1;i++){
		dfs(a[i],a[i],-1,a[i+1],0);
		ans+=st[{a[i],a[i+1]}];//先算出这条路线所需的时间再逐个计算不走某点的时间
	}
	for(int i=0;i<k;i++){
		int tem = ans;
		if(i==0){
			tem -= st[{a[i],a[i+1]}];
		}else if(i==k-1){
			tem -= st[{a[i-1],a[i]}];
		}else{
			tem -= st[{a[i-1],a[i]}];
			tem -= st[{a[i+1],a[i]}];
			dfs(a[i-1],a[i-1],-1,a[i+1],0);
			tem += st[{a[i-1],a[i+1]}];
		}
		cout<<tem<<" ";
	}
}
signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t=1;
  //cin>>t;
  while(t--)solve();
  return 0;
}