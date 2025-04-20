//接龙数列
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
int n;
vector<int>a(N+2);
int get_first(int b){
    while(b){
      b/=10;
      if(b<10)return b;
    }
    return 0;
}
int get_final(int a){
  return a%10;
}
int ans = 0;
int dp[N][10];
void solve(){
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  for(int i=0;i<10;i++){
    dp[0][i] = 0;
  }
  for(int i=1;i<=n;i++){
  	int fi = get_final(a[i]);
    int fr = get_first(a[i]);
  
  	for(int j=0;j<10;j++){
  	dp[i][j] = dp[i-1][j];}
    dp[i][fi] = max(dp[i-1][fr]+1,dp[i][fi]);
    
  }
  for(int i=1;i<10;i++){
    ans = max(ans,dp[n][i]);
  }
  cout<<n-ans;
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