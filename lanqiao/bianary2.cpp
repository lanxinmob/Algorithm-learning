#include <bits/stdc++.h>
#define int long long
using namespace std;
int k;string s;
	char c1,c2;

void solve(){
  cin>>k>>s>>c1>>c2;
  vector<int>b;
  int ans=0;
  for(int i=0;i<s.size();i++){
  	
  	if(s[i]==c1)b.push_back(i);
  	if(s[i]==c2){
  		if(i-k+1<0||!b.size()){
  			continue;
  		}
  		int l=0,r=(int)b.size()-1,mid;
  		while(l+1<r){
  			mid =(l+r+1)>>1;
  			if(b[mid]<=i-k+1)l=mid;
  			else r = mid;
  		}
  		if(b[r]<=i-k+1)l=r;
  		if(b[l]<=i-k+1){
  			ans+=l+1;
  		}
  	}
  }
  cout<<ans;
}
signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t=1;
  
  while(t--)solve();
  return 0;
}