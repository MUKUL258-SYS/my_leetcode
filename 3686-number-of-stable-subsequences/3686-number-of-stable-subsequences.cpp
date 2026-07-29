class Solution {
public:
vector<int>nums;
int n,k;
int mod=1e9+7;
int dp[100002][3][3];
int dfs(int i,int parity,int cnt){
    if(i>=n){
        return parity==2?0:1;

    }
    if(dp[i][parity][cnt]!=-1)return dp[i][parity][cnt];
    int op1=dfs(i+1,parity,cnt);
    int op2=0;
    if(parity==2){
        op2=dfs(i+1,nums[i]%2,1);
    }
    else if(nums[i]%2 != parity){
        op2=dfs(i+1,nums[i]%2,1);
    }
    else{
        if(cnt<k){
            op2=dfs(i+1,parity,cnt+1);
        }
        //op2+=dfs(i+1,parity,1);
    }
    return dp[i][parity][cnt]=(op1+op2)%mod;
    
}
    int countStableSubsequences(vector<int>& nums) {
        this->nums=nums;
        n=nums.size();
        k=2;
        for(int i=0;i<100002;i++){
            for(int j=0;j<3;j++){
                for(int l=0;l<3;l++){
                    dp[i][j][l]=-1;
                }
            }
        }
        return dfs(0,2,0);
    }
};