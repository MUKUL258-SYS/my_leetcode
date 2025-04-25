class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long>ans(n,0);
        unordered_map<long long,vector<long long>>mp;
        for(int i=0;i<n;i++)mp[nums[i]].push_back(i);
        for(auto i:mp){
            vector<long long>v=i.second;
            long long presum=0;
            long long total=0;
            for(auto i:v)total+=i;
            long long m=v.size();
            for(int j=0;j<m;j++){
                 ans[v[j]]-=presum;
                 ans[v[j]]+=((long long)j)*v[j];
                 ans[v[j]]-=(m-j-1)*v[j];
                 ans[v[j]]+=(total-presum-v[j]);
                 presum+=v[j];
            }
        }
        return ans;
    }
};