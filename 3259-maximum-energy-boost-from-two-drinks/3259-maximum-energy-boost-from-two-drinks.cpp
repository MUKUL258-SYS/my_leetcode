class Solution {
public:
vector<vector<long long>>dp;
int n;
vector<int>nums1,nums2;
long long dfs(int h,int drink){
    if(h>=n)return 0;
 if(dp[h][drink]!=-1)return dp[h][drink];
 long long curr=(drink==0)?nums1[h]:nums2[h];
 long long v1=dfs(h+1,drink);
 long long v2=dfs(h+2,drink^1);
 return  dp[h][drink]=curr+max(v1,v2);
}
    long long maxEnergyBoost(vector<int>& eA, vector<int>& eB) {
        n=eA.size();
        dp.resize(n,vector<long long>(2,-1));
        
        nums1=eA;
        nums2=eB;
        return max(dfs(0,0),dfs(0,1));
    }
};