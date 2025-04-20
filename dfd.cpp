vector<int> v = { 1,4,2,7 };
 
sort(v.begin(), v.end());                  //默认从小到大排序
sort(v.begin(), v.end(), less<int>());     //从小到大排序
sort(v.begin(), v.end(), greater<int>());  //从大到小排序
vector<int> v = { 13,1,9,4,2,7};
std::partial_sort( begin(v), next(begin(v), 3), end(v)); // 部分排序前3个元素
 
//排序后v{1 2 4 13 9 7 }
vector<int> v = {15, 12, 9, 10, 7, 6, 3, 8, 4};
std::nth_element( begin(v), next(begin(v), 3), end(v)); // 找到第 3 小的元素并将其放置在正确的位置
 
//排序后v= {4 3 6 7 10 9 12 8 15}
vector<int> v = { 1,4,4,7 };
srand((unsigned int)time(NULL));
random_shuffle(v.begin(), v.end());
vector<int> v1 = { 1,3,5,7 };
 vector<int> v2 = { 2,4,6,8 };
 
 vector<int> d;
 d.resize(v1.size() + v2.size());   //分配空间
 merge(v1.begin(),v1.end(), v2.begin(), v2.end(),d.begin());
 
//执行结果 d = { 1 2 3 4 5 6 7 8 }
vector<int> v = { 1,3,5,7 };  
reverse(v.begin(), v.end());
 
//执行结果 v={7 5 3 1 }