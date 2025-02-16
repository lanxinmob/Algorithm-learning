//P5019 铺设道路
#include<stdio.h>
#include<stdlib.h>
#define N 100005
int main(){
    int n;
    scanf("%d",&n);
    int a[N],dp[N];
    long long ans;
    for (int i = 0; i <n; i++)scanf("%d",&a[i]);
    dp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if(a[i]>a[i-1])dp[i]=dp[i-1]+a[i]-a[i-1];
        else dp[i]=dp[i-1];
    }
    printf("%lld",dp[n-1]);
    return 0;
}