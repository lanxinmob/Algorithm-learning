#include <stdio.h>
#define MAXN 50005

int len, n, m, ans;
int l, r, mid;
int a[MAXN];

int judge()
{
    int cnt = 0;
    int pos = 0;
    for(int i = 1;i <= n+1;i++){
        if(a[i] - pos < mid)
            cnt++;
        else
            pos = a[i];
    }
    return cnt<=m;//最小的最大值
}

int main()
{
    scanf("%d%d%d", &len, &n, &m);
    for(int i = 1; i <= n; i ++)  scanf("%d", &a[i]);
    a[n + 1] = len;
    l = -1;
    r = len+1;
    while(l +1< r)
    {
        mid = l+(r-l)/2;
        if(judge()) l = mid ;
        else r = mid;
    }
    printf("%d\n", l);
    return 0;
}