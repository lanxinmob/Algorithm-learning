//Distributed/Parallel Reservoir Sampling
#include <vector>
#include <random>
#include <iostream>
class Distributed
{
public:
    Distributed(const std::vector<std::vector<int>>& data,int k):
    distributed_data(data),k(k){}
    std::vector<int>sample(){
        std::vector<std::vector<int>> local_samples;//先分别抽样后的sample
        for(const auto& local_data:distributed_data){//每个流抽样
            local_samples.push_back(sampling(local_data,k));
        } 
        return all_reservoir_sampling(local_samples,k);
    }
private:
    int k;
    std::vector<std::vector<int>> distributed_data;

    std::vector<int>  sampling(std::vector<int>& local_data, int k){
        std::vector<int> result(k);
        std::mt19937 rng(std::random_device{}());
        for (int i = 0; i < local_data.size(); i++){
            if(i<k){
              result[i] = local_data[i];
            }else{
              std::uniform_int_distribution<int>dist(0,i);
              if(dist(rng)<k){
                result[dist(rng)] = local_data[i];
              } 
            }
        }
        return result;
    }
    std::vector<int> all_reservoir_sampling(std::vector<std::vector<int>>& local_samples, int k){
        std::vector<int> result(k);
        std::mt19937 rng(std::random_device{}());
        int nums = 0;
        for (const auto& all_sample:local_samples){
            for(int it:all_sample){
            if(nums<k){
              result[nums++] = it;
            }else{
              std::uniform_int_distribution<int>dist(0,nums);
              if(dist(rng)<k){
                result[dist(rng)] = it;
              }nums++ 
            }
        } }
        return result;
    }
};