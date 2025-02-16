//知识考量码
#include<iostream>
#include<vector>
using namespace std;
using i64 = long long;

const int P = 1000000007;
const int M = 31;

i64 quick_power(i64 a,int b){
    i64 res = 1;
    while(b){
        if(b&1){
            res = res*a % P;
        }
        a = a*a % P;
        b>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector c(M,vector<int>(M));
    for (int i = 0; i < M; i++){
        for(int j=0; j <= i; j++){
            if(j==0||i==j){
               c[i][j] = 1;
            }else{
               c[i][j] = (c[i-1][j-1] + c[i-1][j]) %P; 
            } 
        }
    }
vector<i64>cnt(M);
for (int i = M-1,p=0; i >=-1; i--){
    if(i==-1){
       cnt[p]++;
    }else if(k >> i & 1){
       for(int j=0;j<=i;j++){
           cnt[p+j] += c[i][j];
       }
       p++; 
    }
}
i64 ans = 0;
for (int i = 1; i < M; i++){
    ans += cnt[i]*quick_power(n,i)%P;
    ans%=P; 
}
ans++;
cout<<ans%P<<endl;
}
