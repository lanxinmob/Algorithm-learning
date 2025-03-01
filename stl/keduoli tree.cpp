#include<iostream>
#include<set>
#include<iterator>
#include<vector>
struct keduoli
{
    int start;
    int end;
    int color;
    bool operator<(const keduoli& a)const{
        return start<a.start;
    }
};
std::set<keduoli> keduoli_tree;
void  split(int se){
    auto it = keduoli_tree.upper_bound(keduoli{se,se,1});
    it--;//找到包含该端点的区间
    int s = it->start,e = it->end,c = it->color;
    keduoli_tree.erase(it);
    if(s<se)
    keduoli_tree.insert(keduoli{s,se-1,c});
    if(se<e)
    keduoli_tree.insert(keduoli{se,e,c});
}
void merge(){
    std::vector<keduoli>merge;
    for(auto a = keduoli_tree.begin();a!=keduoli_tree.end();a++){
       if(!merge.empty()&&merge.back().color==a->color){
          merge.back().end = a->end;
       }else{
          merge.push_back(*a);
       }
    }
    keduoli_tree.clear();
    for(auto& section:merge){
        keduoli_tree.insert(section);
    }
}
void  revise(int s,int e,int c){
    split(s);
    split(e);
    auto it = keduoli_tree.lower_bound(keduoli{s,s,1});
    std::vector<keduoli>section;
    while (it!=keduoli_tree.end()&&it->start<e)
    {   section.push_back(*it);   
        it++;
    }
    for(auto a:section){
        keduoli_tree.erase(a);
    }
    keduoli_tree.insert(keduoli{s,e,c});
}
int main(){
    int n;
    std::cin>>n;
    int s,e,c;
    for (int i = 0; i < n; i++)
    {   std::cin>>s>>e>>c;
        keduoli_tree.insert(keduoli{s,e,c});
    }
    std::cin>>s>>e>>c;
    revise(s,e,c);
    merge();
    for (auto node:keduoli_tree)
    {
        std::cout<<"["<<node.start<<","<<node.end<<"] is "<<node.color<<"\n";
    }
    return 0;
}