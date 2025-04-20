//LCA Tarjan普通以及迭代
//tarjan是离线查询 批量处理
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =2e5+10;
int dep[N],stjump[N][20];
int n,k; 
typedef pair<int,int> pi;
vector<pi>edge[N];
int a[N],sum[N];
int find(int a){
	if(fa[a]==a)return a;
	return fa[a]= find[fa[a]];
}void unite(int i,int j){
	fa[find(i)] = find(j);
}
int lca(int a,int b){
	st[a] = true;
	fa[a] = b;
	for(auot e:edge[a]){
		if(e!=b){
			tajan(e,a);
			unite(e,a);
		}
	}for(auto &[u,index]:query[a]){
		if(st[u])ans[index] = find(u);
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
		int a,b,index;
		cin>>a>>b>>index;
		adj[b].push_back({a,index});
		adj[a].push_back({b,index});
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