//P1825
#include<iostream>
#include<queue>
using namespace std;
int n,m;
int sx,sy;
const int N=305;
char a[N][N];
bool vis[N][N];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct node
{
    int x,y,t;
};
queue<node>q;
void w(int &nx,int &ny,int t){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(nx!=i&&ny!=j&&a[nx][ny]==a[i][j]){
            nx = i;
            ny = j;
            return;
            }
        }
    }
}
void bfs(){
    q.push((node){sx,sy,0});
    while(!q.empty()){
        node f = q.front();
        q.pop();
        if(a[f.x][f.y]=='='){
            cout<<f.t;
            return;
        }
        if(a[f.x][f.y]>='A'&&a[f.x][f.y]<='Z'){
            w(f.x,f.y,f.t);
        }
        for (int i = 0; i < 4; i++){
            int nx=f.x+dx[i];
            int ny=f.y+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]!='#'&&!vis[nx][ny]){
               vis[nx][ny] = 1;
               q.push((node){nx,ny,f.t+1});
            }
        }
        
    }
    
}
int main(){
    cin>>n>>m;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=1;j<=m;j++){
            a[i][j] = s[j-1];
            if(s[j-1]=='@')sx=i,sy=j;
        }
    }
    bfs();
    return 0;
}