class Solution {
public:
vector<int>nums;
int dp[44][20000];
int helper(int i,long long currx,long long t){
    int n=nums.size();
    if(i>=n){
        if(currx==t)return 0;
        else return INT_MAX;
    }
    if(dp[i][currx]!=-1)return dp[i][currx];
    int op1=helper(i+1,currx,t);
    int op2=helper(i+1,currx^nums[i],t);
    if(op2!=INT_MAX){
        op2+=1;
    }
    return dp[i][currx]=min(op1,op2);

}
    int minRemovals(vector<int>& nums, int target) {
        int x=0;
        this->nums=nums;
        for(auto i:nums)x=x^i;
        if(x==target)return 0;
        for(int i=0;i<44;i++){
            for(int j=0;j<20000;j++){
                dp[i][j]=-1;
            }
        }
        int ans=helper(0,x,target);
        
        return ans==INT_MAX?-1:ans;
    }
};