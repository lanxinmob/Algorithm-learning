#include <bits/stdc++.h>
#define int long long
using namespace std;
#define INF 0x3f3f3f3f
const int N = 1e5+10;
int n;
map<int ,vector<int>>st;
void prim(int a,int pos){
   for(int i=2;i<=a/i;i++){
       if(a%i)continue;
       st[i].push_back(pos);
       while(a%i==0){
         a/=i;
       }
   }if(a>1)st[a].push_back(pos);
   return;
 }
 void solve(){
   cin>>n;
   pair<int ,int >ans={INF,INF};
int x;
   for(int i=1;i<=n;i++){
     cin>>x;
     prim(x,i);
   }
   for(auto [i,j]:st){
      if(j.size()<2)continue;
      if(j[0]<ans.first){
        ans={j[0],j[1]};
      }else if(j[0]==ans.first){
        if(j[1]<ans.second){
          ans = {j[0],j[1]};
        }
      }
   }
cout<<ans.first<<" "<<ans.second;
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