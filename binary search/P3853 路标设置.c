#include <stdio.h>
#define MAXN 10000002

int l, n, k;
int lo, r, mid;
int a[MAXN];

int judge(int mid)
{
    int cnt = 0;
    for(int i=1;i<=n;i++)
		cnt+=(a[i]-a[i-1]-1)/mid;
    return cnt<=k;//最大的最小值
}
int main()
{
    scanf("%d %d %d", &l, &n, &k);
    for(int i = 1; i <= n; i ++)  scanf("%d", &a[i]);
    lo = 0;
    r = l+1;
    while(lo +1< r)
    {
        mid = lo+(r-lo)/2;
        if(judge(mid)) r = mid ;
        else lo = mid;
    }
    printf("%d",r);
    return 0;
}