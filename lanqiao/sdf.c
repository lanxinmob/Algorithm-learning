//最简明的做法
#include <bits/stdc++.h>  
using namespace std;  
int main()
{  
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int N;cin >> N;  
  vector<int> a(N);  
  for(auto &x : a) 
    cin >> x;     
  vector<int> sa = a;//复制一个用来排序的sort.a  
  sort(sa.begin(), sa.end());  
  int k = 0;  
  for(int i = 0; i < N && k < N; i++)
  {  
    if(a[i] == sa[k])  
      k++;   
  }  
  cout << (N - k);  
  return 0;  
}
//做法类似上一次的草稿纸题，但是不知道为什么没能通过
/*#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  int n,ma,ans=0;
  scanf("%d",&n);
  int*a=(int*)malloc(n*sizeof(int));
  int*vis=(int*)calloc(n,sizeof(int));
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }ma=a[n-1];
  for(int i=n-2;i>=0;i--){
    if(ma<a[i])vis[i]=1;
    ma = ma<a[i]?ma:a[i];
  }
  ma = a[0];
  for(int i=1;i<n;i++){
  if(ma<a[i])vis[i]=1;
    if(vis[i])ma = ma>a[i]?ma:a[i];
  }
  for(int i=0;i<n;i++){
    if(vis[i])ans++;
  }
  printf("%d",ans);
  free(a);
  free(vis);
  return 0;
}*/
//没搞懂原理，但是过了 但是明显有问题
/*
#include<stdio.h>
int main(){
  int n;
  scanf("%d",&n);
  int a[n],pos;
for(int i = 1; i <= n; ++ i) {
    scanf("%d",&a[i]);
    if(a[i - 1] > a[i]) {
      pos = i;
      break;
    }
  }
  printf("%d",n-pos+1);
}*/
/*
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int n;
    scanf("%d", &n);

    int* a = (int*)malloc(n * sizeof(int));
    int* b = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i]; 
    }
    qsort(b, n, sizeof(int), cmp);
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[cur]) {
            ans++;
        } else {
            cur++;
        }
    }

    printf("%d\n", ans);

    free(a);
    free(b);
}