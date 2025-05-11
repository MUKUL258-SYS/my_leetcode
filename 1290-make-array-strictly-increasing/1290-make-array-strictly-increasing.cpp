class Solution {
public:
int n,m;
int dp[2005][2005][4];
int dfs(int i,int j,int p,vector<int>&arr1,vector<int>&arr2,int take){
    if(i>=n)return 0;
    j=upper_bound(arr2.begin(),arr2.end(),p)-arr2.begin();
    if(dp[i][j][take]!=-1)return dp[i][j][take];
    if(j>=m&&arr1[i]<=p)return 2001;
    int tuke=2001;
    int notake=2001;
    if(j<m){
        tuke=1+dfs(i+1,j+1,arr2[j],arr1,arr2,1);
    }
    if(arr1[i]>p){
        notake=dfs(i+1,j,arr1[i],arr1,arr2,0);
    }
    return dp[i][j][take]=min(tuke,notake);
}
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        n=arr1.size();
        m=arr2.size();
        memset(dp,-1,sizeof(dp));
        sort(arr2.begin(),arr2.end());
        int ans= dfs(0,0,-1,arr1,arr2,0);
       return ans>=2001?-1:ans;
    }
};
