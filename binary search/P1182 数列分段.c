#include<stdio.h>
#define N 1000000
int n,m;
int a[N];

int judge(int mid){
    int sum=0,num=0;
    for (int i = 1; i <=n; i++)
    {   
        if (a[i]+sum<=mid)sum+=a[i];
        else sum=a[i],num++;
    } 
    return num<m;//最大的最小值
}
int main()
{   int r=0,l=0;
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        r+=a[i];
        l=l>a[i]?l:a[i];
    }
    r++,l--;
    while(l+1<r){
    int mid = l+(r-l)/2;
    if(judge(mid))r=mid;
    else l=mid;
    }
    printf("%d",r);
    return 0;
}