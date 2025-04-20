//异或和之和 拆位、贡献法
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], cnt[25][5], n; //cnt[i][j]: 第i位为j的个数
long long ans;

int main()
{
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
    a[i] ^= a[i - 1];//计算前缀异或和
  }
  /*暴力 可以过8个
  for(int i=1;i<=n;i++){
   for(int j=i;j<=n;j++){
     ans += a[i-1] ^ a[j];
   }
  }
  */
for(int i = 0; i <= 20; i++)
     for(int j = 0; j <= n; j++)
      cnt[i][a[j]>>i & 1]++;
for(int i=0;i<=20;i++){
	ans +=(long long)cnt[i][1] * cnt[i][0] *(1<<i);
}
  printf("%lld", ans);
}