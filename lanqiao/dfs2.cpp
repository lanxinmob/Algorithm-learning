//买瓜 dfs 剪枝优化
//满足要求返回 无法达到返回 无法更优返回
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int N = 40;
int a[N];
int n,m,ans=INF;
double s[N];
void dfs(int u,double v,int cnt){
  if(v==m){ans = min(ans,cnt);
     return;}
  if(v>m||v+s[u]<m)return;
  if(u>=n)return;
  if(cnt>ans)return;
  dfs(u+1,v,cnt);
  dfs(u+1,v+a[u]/2.0,cnt+1);
  dfs(u+1,v+a[u],cnt);   
}
void solve(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }sort(a,a+n,[&](int x,int y){return x>y;});
  for(int i=n-1;i>=0;i--){
    s[i] = s[i+1] +a[i];
  }
  dfs(0,0.0,0);
  if(ans==INF)cout<<-1;
  else{cout<<ans;}
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