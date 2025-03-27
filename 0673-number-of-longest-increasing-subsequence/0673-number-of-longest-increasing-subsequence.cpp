class Solution {
public:
vector<int>nums;
pair<int,int>dfs(int curr,int prev,vector<vector<pair<int,int>>>&dp){
    if(curr==nums.size())return {0,1};
    if(dp[curr][prev+1].first!=-1)return dp[curr][prev+1];
    int length=0;
    int cnt=0;
    if(prev==-1||nums[prev]<nums[curr]){
        pair<int,int>include=dfs(curr+1,curr,dp);
        if(include.first+1>length){
            length=include.first+1;
            cnt=include.second;
        }
        else if(include.first+1==length){
            cnt+=include.second;
        }
    }
    pair<int,int>exclude=dfs(curr+1,prev,dp);
    if(exclude.first>length){
        length=exclude.first;
        cnt=exclude.second;
    }
    else if(exclude.first==length){
        cnt+=exclude.second;
    }
    return  dp[curr][prev+1]={length,cnt};
}
    int findNumberOfLIS(vector<int>& nums) {
        this->nums=nums;
       vector<vector<pair<int,int>>>dp(nums.size()+5,vector<pair<int,int>>(nums.size()+5,make_pair(-1,-1)));
       pair<int,int>p=dfs(0,-1,dp);
       return p.second;
    }
};