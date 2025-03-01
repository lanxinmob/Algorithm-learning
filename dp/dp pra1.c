//舞狮(蓝桥)
#include <stdio.h>
#include <stdlib.h>
void solve(){
  int n;
  scanf("%d",&n);
  int**dp=(int**)malloc((n+1)*sizeof(int*));
  int**a=(int**)malloc((n+1)*sizeof(int*));
  for (int i = 0; i <= n; i++) {
        a[i] = (int *)malloc((n + 1) * sizeof(int));
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      scanf("%d",&a[i][j]);
      dp[i][j] = 1e9;
    }
  }//初始化起点
  if(a[1][1]%2==0)dp[1][1] = n;
  else dp[1][1] = 0;

  for(int i=2;i<=n;i++){//初始化第一行
    if(a[1][i]%2==a[1][i-1]%2)dp[1][i] = dp[1][i-1];
    else break;
  }
  for(int i=2;i<=n;i++){//初始化第一列
    if(a[i][1]%2==0)dp[i][1] = dp[i-1][1]+n;
    else dp[i][1] = dp[i-1][1];
  }
  for(int i=2;i<=n;i++){
    for(int j=2;j<=n;j++){
      if(a[i][j]%2==a[i][j-1]%2)dp[i][j] = dp[i][j]<dp[i][j-1]?dp[i][j]:dp[i][j-1];//从左转移
      if(a[i][j]%2==0)dp[i][j] = dp[i][j]<dp[i-1][j]+n?dp[i][j]:dp[i-1][j]+n;//从上转移
      else dp[i][j] = dp[i][j]<dp[i-1][j]?dp[i][j]:dp[i-1][j];
    }
  }
  if(dp[n][n]!=1e9)printf("%d\n",dp[n][n]);
  else printf("NO!\n");
}
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)solve();
  return 0;
}