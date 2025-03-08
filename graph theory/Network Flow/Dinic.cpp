//网络流 Dinic算法
//最大流即最小割
#include<iostream>
#include<vector>
#include<queue>
#include<limits>
using ll = long long;

template<typename T>
struct Flow_ {
    const int n;
    const T inf = std::numeric_limits<T>::max();//某个数据类型的最大值
    struct Edge{
        int to;
        T w;
        Edge(int t,T w):to(to),w(w){}
    };
    std::vector<Edge>ver;
    std::vector<std::vector<int>> h;
    std::vector<int> cur,d;
    Flow_(int n):n(n+1),h(n+1){}
    void add(int u,int v,int w){
         h[u].push_back(ver.size());//存储边的索引
         ver.emplace_back(v,w);
         h[v].push_back(ver.size());
         ver.emplace_back(u,0);//反向边 增广路径
    }
    bool bfs(int s,int t){//检查是否有s到t的路径
         d.assign(n,-1);//构建level graph
         d[s]=0;
         std::queue<int>q;
         q.push(s);
         while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(auto it:h[x]){
                auto[y,w] = ver[it];
                if(w && d[y]==-1){
                    d[y]=d[x]+1;//d是层级
                    if(y==t)return true;
                    q.push(y);
                }
            }
         }return false;
    }
    T dfs(int u,int t,T f){
         if(u==t)return f;
         auto r = f;
         for (int& i = cur[u]; i <h[u].size(); i++)
         {    auto j=h[u][i];
              auto &[v,c] =ver[j];
              auto &[u,rc] =ver[j^1];
              if(c&&d[v]==d[u]+1){
                auto a =dfs(v,t,std::min(r,c));//阻塞流容量blocking flow
                c-=a;//当前边剩余流量
                rc+=a;//更新反向边容量
                r-=a;//当前路径最多可过流量
                if(!r)return f;
              }
         }
         return f-r;
    }
    T work(int s,int t){
        T ans=0;
        while(bfs(s,t)){
          cur.assign(n,0);
          ans+=dfs(s,t,inf);
        }return ans;
    }
};   
using Flow = Flow_<int>;      