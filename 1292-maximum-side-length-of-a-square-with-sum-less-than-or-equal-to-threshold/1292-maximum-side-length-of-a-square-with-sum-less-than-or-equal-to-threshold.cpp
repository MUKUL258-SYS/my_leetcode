class Solution {
public:
int t;
vector<vector<int>> pre(vector<vector<int>>&mat){
    int n=mat.size();
    int m=mat[0].size();
   vector<vector<int>>dp(n,vector<int>(m,0));
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        dp[i][j]=mat[i][j];
        dp[i][j]+=(i?dp[i-1][j]:0);
        dp[i][j]+=(j?dp[i][j-1]:0);
        dp[i][j]-=(i&&j?dp[i-1][j-1]:0);
    }
   }
   return dp;
}
bool helper(int k,vector<vector<int>>&grid){
     int n=grid.size();
     int m=grid[0].size();
     for(int i=0;i+k<=n;i++){
        for(int j=0;j+k<=m;j++){
        int v=grid[i+k-1][j+k-1];
        v+=(i&&j?grid[i-1][j-1]:0);
        v-=(j?grid[i+k-1][j-1]:0);
        v-=(i?grid[i-1][j+k-1]:0);
        if(v<=t)return true;
        }
     }
     return false;
}
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
      vector<vector<int>>grid=pre(mat);
        int n=mat.size();
        int m=mat[0].size();
        t=threshold;
        int s=1;
        int e=min(n,m);
        int ans=0;
        while(s<=e){
            int mid=(s+e)/2;
         if(helper(mid,grid)){
            ans=max(ans,mid);
            s=mid+1;
         }
         else{
            e=mid-1;
         }
        }
        return ans;
        
    }
};