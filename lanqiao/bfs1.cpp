#include <bits/stdc++.h>
#define int long long
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int ddx[8]={1,1,1,0,0,-1,-1,-1};
int ddy[8]={0,1,-1,1,-1,0,1,-1};
int st_road[52][52];
int st_sea[52][52];
int ans;
int n,m; int g[52][52];
typedef pair<int,int> pi;
bool check(int i,int j){
	if(i>=0&&i<n&&j>=0&&j<m)return true;
	return false;
}
void bfs_road(int x,int y){
	queue<pi>q;
	 q.push({x,y});
	 st_road[x][y] = 1;
	 while(q.size()){
	 	auto a = q.front();
	 	q.pop();
	 	for(int i=0;i<4;i++){
	 		int nx = a.first+dx[i];
	 		int ny = a.second+dy[i];
	 		if(check(nx,ny)&&g[nx][ny]&&!st_road[nx][ny]){
	 			st_road[nx][ny] = 1;
	 			q.push({nx,ny});
	 		}
	 	}
	 }
}
void bfs_sea(int x,int y){
	 queue<pi>q;
	 q.push({x,y});
	 st_sea[x][y] = 1;
	 while(q.size()){
	 	auto a = q.front();
	 	q.pop();
	 	for(int i=0;i<8;i++){
	 		int nx = a.first+ddx[i];
	 		int ny = a.second+ddy[i];
	 		if(check(nx,ny)&&!g[nx][ny]&&!st_sea[nx][ny]){
	 			st_sea[nx][ny] = 1;
	 			q.push({nx,ny});
	 		}
	 		if(check(nx,ny)&&g[nx][ny]&&!st_road[nx][ny]){
	 			ans++;
	 			bfs_road(nx,ny);
	 		}
	 	}
	 }
}
void solve(){
  ans =0 ;
  cin>>n>>m;
  for(int i=0;i<n;i++){
  	string s;cin>>s;
  	for(int j=0;j<m;j++){
  	 g[i][j] = s[j]-'0';
  	 st_road[i][j] = st_sea[i][j] = 0;
  	}
  }
  int flag = 0;
for(int i=0;i<n;i++){
  	for(int j=0;j<m;j++){
  	 if(i==0||i==n-1||j==0||j==m-1){
  	 	if(!g[i][j]&&!st_sea[i][j]){
  	 		flag=1;
  	 		bfs_sea(i,j);
  	 	}
  	 }
  	}
  }if(!flag)
    ans=1;
cout<<ans<<"\n";
}
signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin>>t;
  while(t--)solve();
  return 0;
}