//区间dp 状态定义
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define INF 0x3f3f3f3f
const int N = 5e3+10;
int dp[N][N];
int a,b,n,m;
const int mod = 998244353;
 void solve(){
   string s;cin>>s;
   int ans = 0;
   for(int i=2;i<=s.size();i++){
   	for(int l=0;l+i-1<s.size();l++){
   		if(s[l]>s[l+i-1]){
   			dp[l][l+i-1] = 1;
   		}else if(s[l]==s[l+i-1]){
   			dp[l][l+i-1] = dp[l+1][l+i-2];
   		}
   		ans +=dp[l][l+i-1];
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