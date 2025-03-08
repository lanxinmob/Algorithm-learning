//种类并查集 P1525关押罪犯
#include<iostream>
#include<algorithm>
int read(){
    int k=0,f=1;
    char ch = getchar();
    while (ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9')
    {
        k = k*10+ch-'0';
        ch = getchar();
    }
    return k*f;
}
struct data
{
    int a,b,w;
}c[100005];
int cmp(data&a,data &b){
    return a.w>b.w;
}
int fa[400005],rank[400005];//根节点 高度
int find(int a){
    return fa[a]==a?a: fa[a]=find(fa[a]);//找他们的根节点 缩短路径
}
int query(int a,int b){
    return find(a) ==find(b);//看他们的根节点是否为同一个即是否为同一集合
}
void merge(int a,int b){
    int x=find(a),y=find(b);
    if(rank[x]>=rank[y]){
        fa[y]=x;
    }else{
        fa[x]=y;
    }if(x!=y&&rank[x]==rank[y]){
        rank[x]++;
    }
}
void init(int n){
    for(int i=0;i<n;i++){
        rank[i] = 1;
        fa[i] = i;
    }
}
int main(){
    int n=read(),m=read();
    init(n*2);
    for(int i=0;i<m;i++){
        c[i].a=read();
        c[i].b=read();
        c[i].w=read();
    }
    std::sort(c,c+m,cmp);
    for(int i=0;i<m;i++){//怨气从大往小排
        if(query(c[i].a,c[i].b)){//敌人的敌人是朋友 当出现的是朋友怨气值最小
           printf("%d\n",c[i].w);
           break;
        }
        merge(c[i].a,c[i].b+n);
        merge(c[i].b,c[i].a+n);
        if(i==m-1)printf("0\n");
    }
    return 0;
}