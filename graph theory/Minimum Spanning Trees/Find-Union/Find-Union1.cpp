//P1955 程序自动分析
//查并集 离散化处理
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
struct data
{
    int a,b,w;
}c[100005];
int cmp(data&a,data &b){
    return a.w>b.w;
}int fa[2000005];
std::vector<int>nums;
int find(int a){
    return fa[a]==a?a: fa[a]=find(fa[a]);//找他们的根节点 缩短路径
}
int query(int a,int b){
    return find(a) ==find(b);//看他们的根节点是否为同一个即是否为同一集合
}
void merge(int a,int b){
    int x=find(a),y=find(b);
    if(x!=y){
       fa[y]=x;
    }
}
void init(int n){
    for(int i=0;i<n;i++){
        fa[i] = i;
    }
}
void solve(){
    int n;std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>c[i].a>>c[i].b>>c[i].w;
        nums.push_back(c[i].a);
        nums.push_back(c[i].b);
    }
    std::sort(nums.begin(),nums.end());//去重排序 简化索引
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    init(nums.size());
    std::sort(c,c+n,cmp);
    for(int i=0;i<n;i++){
        int a=lower_bound(nums.begin(),nums.end(),c[i].a)-nums.begin();
        int b=lower_bound(nums.begin(),nums.end(),c[i].b)-nums.begin();
        if(c[i].w==1){
        merge(a,b);
    }else{
        if(find(a)==find(b)){
          printf("NO\n");
          return;
        }
    }
    }
    printf("YES\n");
}
int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t;
    std::cin>>t;
    while (t--)solve();
    
    return 0;
}