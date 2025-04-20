//1.无重复字符的最长子串
int solve(string s){
    int hash[128] = {0};
    int l=0, r=0;
    int len =0, n = s.size();
    while (r<n)
    {
        hash[s[r]]++;
        while(hash[s[r]]>1){
            hash[r[l]]--;
            l++;
        }len = max(len,l-r+1);
        r++;
    }
    return len;
}
//2.最大连续1的个数(0可翻转k次)
int solve(vector<int>& nums,int k){
    int array[2] = {0};
    int l=0, r=0;
    int len =0, n = s.size();
    while (r<n)
    {
        array[nums[r]]++;
        while(array[0]>k){
            array[nums[l]]--;
            l++;
        }len = max(len,l-r+1);
        r++;
    }
    return len;
}
//3.将x减到0的最小操作数
int solve(vector<int>& nums,int k){
    int sum = 0;
    for(auto e:nums)sum+=e;
    int target = sum - x;
    if(target<0)return -1;
    int ans = -1;
    int l=0, r=0;
    int n = s.size(),tem = 0;
    while (r<n)
    {
        tem += nums[r];
        while(tem>target){
            tem -= num[l];
            l++;
        }if(target == tem){
        ans = max(ans,l-r+1);}
        r++;
    }if(ans ==-1)return -1;
    return n-ans;
}
//4.最小覆盖子串
int solve(string s,string t){
    int hash1[128] = {0},hash2[128] = {0};
    int l=0, r=0;
    int kind = 0;
    int len =0, n = s.size();
    for(auto a:t){
        hash1[a]++;
        if(hash1[a]==0)kind++;
    }
    int cout = 0,begin = -1,minlen = INT_MAX;
    while (r<n)
    {
        hash2[s[r]]++;
        if(hash1[s[r]]==hash2[s[l]]){
            cout++;
        }
        while(cout == kind){
            if(r-l+1<minlen){
                minlen = r-l+1;
                begin = l;
            }
            if(hash1[s[l]]==hash2[s[r]]){
                cout--;
            }
            hash2[s[l]]--;
            l++;
        }
        r++;
    }
    return s.substr(begin,minlen);
}