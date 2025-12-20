class Solution {
public:
typedef long long ll;
int n;
unordered_map<ll,ll>mp;
vector<ll>dp;
ll dfs(int i,vector<long long>&nums){
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    long long take=0,notake=0;
    notake=dfs(i+1,nums);
    int j=lower_bound(begin(nums)+i+1,end(nums),nums[i]+3)-begin(nums);
    take=(nums[i]*mp[nums[i]])+dfs(j,nums);
    return dp[i]=max(take,notake);
}
    long long maximumTotalDamage(vector<int>& power) {
        for(auto i:power){
            mp[i]++;
        }
        vector<ll>nums;
        for(auto i:mp){
       nums.push_back(i.first);
        }
        sort(nums.begin(),nums.end());
        n=nums.size();
        dp.assign(n,-1);
        return dfs(0,nums);
    }
};