//单调队列 二维滑动窗口 
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define INF 0x3f3f3f3f
const int N = 1e3+10;
int g[N][N];
int a,b,n,m;
int lmin[N][N],cmin[N][N];
int lmax[N][N],cmax[N][N];
int q[N];
const int mod = 998244353;
 void solve(){
   cin>>n>>m>>a>>b;
   for(int i=0;i<n;i++)
   	for(int j=0;j<m;j++)
   		cin>>g[i][j];
   for(int i=0;i<n;i++){
      int h=0,t=-1;
      for(int j=0;j<m;j++){
          if(h<=t &&q[h]<j-b+1){//超出窗口移除队首元素
          	h++;
          }
          while(h<=t&&g[i][q[t]]<g[i][j])
            t--;
          q[++t] = j;
          if(j-b+1>=0)
          lmax[i][j-b+1] = g[i][q[h]];
      }
   }
   for(int j=0;j<m;j++){
      int h=0,t=-1;
      for(int i=0;i<n;i++){
          if(h<=t &&q[h]<i-a+1){//超出窗口移除队首元素
          	h++;
          }
          while(h<=t&&lmax[q[t]][j]<lmax[i][j])
            t--;
          q[++t] = i;
          if(i-a+1>=0)
          cmax[i-a+1][j] = lmax[q[h]][j];
      }
   }for(int i=0;i<n;i++){
      int h=0,t=-1;
      for(int j=0;j<m;j++){
          if(h<=t &&q[h]<j-b+1){//超出窗口移除队首元素
          	h++;
          }
          while(h<=t&&g[i][q[t]]>=g[i][j])
            t--;
          q[++t] = j;
          if(j-b+1>=0)
          lmin[i][j-b+1] = g[i][q[h]];
      }
   }
   for(int j=0;j<m;j++){
      int h=0,t=-1;
      for(int i=0;i<n;i++){
          if(h<=t &&q[h]<i-a+1){//超出窗口移除队首元素
          	h++;
          }
          while(h<=t&&lmin[q[t]][j]>=lmin[i][j])
            t--;
          q[++t] = i;
          if(i-a+1>=0)
          cmin[i-a+1][j] = lmin[q[h]][j];
      }
   }int ans=0;
   for(int i=0;i<n;i++){
   	for(int j=0;j<m;j++){
   		ans = (ans+cmax[i][j]*cmin[i][j]%mod)%mod;
   	}
   }
   cout<<ans;
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