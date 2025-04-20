//优先队列 链表
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N =5e5+10;
typedef pair<int ,int> pi;
priority_queue<pi,vector<pi>,greater<pi>>q;
int n,k;
int a[N],r[N],l[N];
int st[N];//记录有没有被删除
void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		q.push({a[i],i});
		r[i] = i+1;
		l[i] = i-1;
		st[i] = a[i];
		if(i==n-1)
		r[i] = -1;
	}
	while(k){
		pi it=q.top();
		q.pop();
		int pos = it.second;
		if(it.first!=st[pos]){
			q.push({st[pos],pos});
			continue;
		}
		k--;
		if(l[pos]>=0)st[l[pos]]+=it.first;
		if(r[pos]>=0)st[r[pos]]+=it.first;
		if(l[pos]>=0)r[l[pos]] = r[pos];
		if(r[pos]>=0)l[r[pos]] = l[pos];
		st[pos] = -1;
	}
	for(int i=0;i<n;i++){
		if(st[i]!=-1)cout<<st[i]<<" ";
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