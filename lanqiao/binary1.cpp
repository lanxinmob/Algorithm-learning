#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[10000],b[10000];
bool checkm(int mid){
   for(int i=0;i<n;i++){
     if(b[i]<a[i]/mid){
       return true;
     }
   }return false;
}
bool checkx(int mid){
   for(int i=0;i<n;i++){
     if(b[i]>a[i]/mid){
       return true;
     }
   }return false;
}
void binm(){
  int min,l=1,r=1e9,mid;
  while(l+1<r){
    mid =(r+l)>>1;
    if(checkm(mid)) l = mid;
    else r = mid;
  }cout<<r<<" ";
}
void binx(){
  int l=1,r=1e9,mid;
  while(l+1<r){
    mid = (r+l+1)>>1;
    if(checkx(mid)) r = mid;
    else l = mid;
  }cout<<l;
}
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i];
  }
  binm();
  binx();
}
signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t=1;
  
  while(t--)solve();
  return 0;
}