#include<iostream>

int idx,son[50001][26];
bool b[10005][1001];
char str[10010];
int n,l,m;
void insert(char*str,int x){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]){
            son[p][u]=++idx;
        }p=son[p][u];//更新节点
    }b[p][x]==true;//记录在某行出现
}
void check(char*str){
    int p=0,flag=1;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u]){
            flag=0;
            break;
        }p=son[p][u];
    }if(flag){
        for(int i=1;i<=n;i++){
            if(b[p][i])std::cout<<i<<" ";
        }
    }std::cout<<"n";
}
int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    std::cin>>n;
    for(int i=1;i<=n;i++){
        std::cin>>l;
        for(int j=0;j<l;j++){
            std::cin>>str;
            insert(str,i);
        }}
        std::cin>>m;
        for(int i=0;i<m;i++){
            std::cin>>str;
            check(str);
            }
    return 0;
}
