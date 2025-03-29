//朴素的Dijkstra模板 贪心思想 有选择的松弛
//q全局变量点的数量  v起始节点  f终结点 
//prev[i]到i节点最短路径前一节点  dist[i]v到i节点最短路径长度
void dijkstra(int v,int f,int prev[],int dist[]){
    int min,temp,k;
    int flag[q];//表示到该节点最短路径是否获取
/*1.初始化*/
    for (int i = 0; i < q; i++)
    {
        flag[i] = 0;
        dist[i] = matrix[vs][i];
        prev[i] = vs;
    }
    flag[vs] = 1;//这个初始化把起点及相邻节点更新了，但不手动更新相邻节点也可以，则flag[vs]=0;
    dist[vs] = 0;
/*2.一个大循环 两个小循环*/
    for (int i = 0; i < q; i++)
    {   min = INF;
        for (int j = 0; j < q; j++)//在未获取最短路径点中找到离vs最近的点
        {
            if (!flag[j]&&dist[j]<min)
            {
                min = dist[j];
                k = j;   
            }
        }
        flag[k] = 1;
        if(k==f)break;
        for (int j = 0; j < q; j++)//松弛操作
        {   temp = (matrix[k][j]==INF)?INF:min+matrix[k][j];//防止溢出
            if(!flag[j]&&dist[j]>temp)
            {
                prev[j] = k;
                dist[j] = temp;
            }
        }  
    }
}

