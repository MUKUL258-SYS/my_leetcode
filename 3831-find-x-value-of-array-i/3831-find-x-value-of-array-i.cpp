class Solution {
public:
vector<int>nums;
vector<vector<long long>>dp;
int n,k;
long long dfs(int i,long long multiplier,int x){
    if(i==n){
        return 0;
    }
    if(dp[i][multiplier+1]!=-1)return dp[i][multiplier+1];
    long long cnt=0;
    //if(nums[i]==x)cnt++;
    long long take=0;
    long long nottake=0;
    if(multiplier==-1){
        if(nums[i]==x)cnt++;
         take=cnt+dfs(i+1,nums[i],x);
         nottake=dfs(i+1,-1,x);
    }else{
      //   multiplier=(multiplier*nums[i])%k;
         
         if(((multiplier*nums[i])%k)==x)cnt++;
         take=cnt+dfs(i+1,(multiplier*nums[i])%k,x);
       //  nottake=dfs(i+1,-1,x);
    }
    return dp[i][multiplier+1]=(take+nottake);
}
    vector<long long> resultArray(vector<int>& nums, int k) {
        n=nums.size();
        this->k=k;
       // this->nums=nums;
    for(int i=0;i<nums.size();i++){
        nums[i]=nums[i]%k;
    }
    this->nums=nums;
      vector<long long>vp;
      for(int i=0;i<k;i++){
        dp.assign(n,vector<long long>(k+1,-1));

          vp.push_back(dfs(0,-1,i));
      }
      return vp;
    }
};