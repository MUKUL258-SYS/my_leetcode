class Solution {
public:
int n;
int mod;
//vector<vector<int>>arr;
int dp[51][1005];
int dfs(int i,int target,vector<vector<int>>&arr){
    if(target<0)return INT_MIN;
    if(target==0)return 1;
    if(i>=n)return INT_MIN;
    //if(target<0)return INT_MIN;
    //int ans=dfs(i+1,target);
    if(dp[i][target]!=-1)return dp[i][target];
    int ans=0;
    int op1=dfs(i+1,target,arr);
    if(op1!=INT_MIN)ans=(ans+op1)%mod;
        int freq=arr[i][0];
        int marks=arr[i][1];
        
        for(int k=0;k<freq;k++){
            int t=target-((k+1)*marks);
             int ways=dfs(i+1,t,arr);
             if(ways!=INT_MIN){
                ans=(ans+ways)%mod;
             }
            //(i+1,target);

        }
    
    return dp[i][target]=ans;
}
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        n=types.size();
        mod=1e9+7;
        //this->target=target;
        //arr=types;
        for(int i=0;i<51;i++){
            for(int j=0;j<1004;j++){
                dp[i][j]=-1;
            }
        }
        return dfs(0,target,types);
    }
};