//P1893 团伙
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
struct data
{
    int a,b;
    char w;
}c[5005];
int fa[1005],enemy[1005];
int find(int a){
    return fa[a]==a?a: fa[a]=find(fa[a]);//找他们的根节点 缩短路径
}
void merge(int a,int b){
    int x=find(a),y=find(b);
    if(x!=y){
       fa[y]=x;
    }
}
void init(int n){
    for(int i=1;i<=n;i++){
        fa[i] = i;
        enemy[i] = 0;
    }
}
void solve(){
    int n,m;
    std::cin>>n>>m;
    for(int i=0;i<m;i++){
        std::cin>>c[i].w>>c[i].a>>c[i].b;
    }
    init(n);
    std::set<int>np;
    for(int i=0;i<m;i++){
        if(c[i].w=='F'){
        merge(c[i].a,c[i].b);
    }else{
        if(!enemy[c[i].a])enemy[c[i].a]=find(c[i].b);
        else merge(enemy[c[i].a],c[i].b);
        if(!enemy[c[i].b])enemy[c[i].b]=find(c[i].a);
        else merge(enemy[c[i].b],c[i].a);
    }
    }
    for(int i =1;i<=n;i++){
        np.insert(find(i));
    }
    printf("%d\n",np.size());
}
int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    int t=1;
    //std::cin>>t;
    while (t--)solve();
    return 0;
}
