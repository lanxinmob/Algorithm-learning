//Reservoir Sampling
#include<iostream>
#include<vector>
#include<random>

std::mt19937 rng(std::random_device{}());
std::uniform_int_distribution<int> dist(0,i);
int j = dist(rng);

class Reservoir
{
public:
    std::vector<int>tep;
    Reservoir(std::vector<int>& nums){
        tep = nums;
    }
    int choose(int aim){
        int c = 0;
        int idx = 0;
        for (int i = 0; i < tep.size(); i++)
        {   
            if(tep[i] == aim){//随机选择特定值
                c++;
                if(rand()%c==0)
                idx = i;
            }
        }return idx;
    }
};

class Reservoir
{
public:
    std::vector<int>tep,result;
    Reservoir(std::vector<int>& nums,int k):tep(nums),result(k,0){}
    std::vector<int> choose(int k){
        for (int i = 0; i < tep.size(); i++)
        {   
            if(i<result.size()){//随机选择k个
                result[i] = tep[i];
            }else 
            {   
                int j = rand()%i;
                if(j<result.size())
                result[j] = tep[i];
            }
        }return result;
    }
};

