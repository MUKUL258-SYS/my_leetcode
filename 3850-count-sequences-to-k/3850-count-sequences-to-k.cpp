class Solution {
public:
vector<int>nums;
int n;
long long k;
unordered_map<string,long long>dp;
long long dfs(int idx,long long num,long long den){
    if(idx==n){
     if (num<k || num<den) return 0; 
     return (num == k * den);
     }
    
    long long g=__gcd(num,den);
    num/=g;
    den/=g;
  string str=to_string(idx)+"$"+to_string(num)+"$"+to_string(den);
  if(dp.find(str)!=dp.end())return dp[str];
    long long ans=0;
    ans+=dfs(idx+1,num,den);
    ans+=dfs(idx+1,num*nums[idx],den);
    ans+=dfs(idx+1,num,den*nums[idx]);
    return dp[str]=ans;

}
    int countSequences(vector<int>& nums, long long k) {
       this->nums=nums;
       this->k=k;
       n=nums.size();
        return dfs(0,1,1);
    }
};