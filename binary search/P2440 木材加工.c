#include<stdio.h>
#define N 1000000
int n,k;
int a[N];

int judge(int mid){
    int num=0;
    for (int i = 1; i <=n; i++)num+=a[i]/mid;
    return num<k;//尽量大
}
int main()
{   int r=0,l=0;
    scanf("%d %d",&n,&k);
    for (int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        r=r>a[i]?r:a[i];
    }
    r++; 
    while(l+1<r){
    int mid = l+(r-l)/2;
    if(judge(mid))r=mid;
    else l=mid;
    }
    if(judge(r))printf("%d",l);
    else printf("%d",r);
    return 0;
}