//P3876
#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;
using ll = long long;
string str;
int n,l,m;
unordered_map<string,set<int>>word;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    n = read();
    for(int i=1;i<=n;i++){
        l = read();
        for(int j=0;j<l;j++){
            cin>>str;
            word[str].insert(i);
        }}
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>str;
            if(word[str].empty()){
             cout<<"\n";
             continue;
            }bool flag = false;
            for(auto& a: word[str]){
            	if(flag)cout<<" ";
             cout<<a;
            flag = true;
        }cout<<endl;}
    //int t=1;
    //while(t--)solve();
    return 0;
}