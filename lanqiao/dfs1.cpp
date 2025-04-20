#include <bits/stdc++.h>
#define int long long
using namespace std;
struct a{
	int t,d,l;
}pl[30];
bool st[30];
int num;
bool dfs(int u,int time){
	if(u>=num)return true;
	for(int i=0;i<num;i++){
		if(st[i])continue;
		if(pl[i].t+pl[i].d>=time){
			int t=max(pl[i].t,time)+pl[i].l;
			st[i]=true;
			if(dfs(u+1,t))return true;
			st[i]=false;
		}
	}return false;
}
void solve(){
  cin>>num; 
  for(int i=0;i<num;i++){
  	cin>>pl[i].t>>pl[i].d>>pl[i].l;
  	st[i] = false;
  }
  if(dfs(0,0)) cout<<"YES\n";
  else cout<<"NO\n";
  for(int i=0;i<num;i++){
  	st[i]=false;
  }
}
signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin>>n;
  while(n--)solve();
  return 0;
}