class Solution {
public:
int target;
vector<vector<int>>mat,dp;
int dfs(int row,int sum){
    int n=mat.size();
    int m=mat[0].size();
    if(row>=n){
        return abs(target-sum);
    }
    if(dp[row][sum]!=-1)return dp[row][sum];
    int diff=INT_MAX;
    for(int j=0;j<m;j++){
     diff=min(diff,dfs(row+1,sum+mat[row][j]));
       if(diff==0){
        break;
       }
    }
    return dp[row][sum]=diff;

}
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        this->mat=mat;
        this->target=target;
    dp.resize(75,vector<int>(5000,-1));
 
return dfs(0,0);

    }
};