class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,2));

        for(int k=0;k<n;k++){
            for(int j=0;j<k;j++){
                int diff=arr[k]-arr[j];
                if(mp.count(diff) && mp[diff]<j){
                    int i=mp[diff];
 dp[j][k]=max(dp[j][k],1+dp[i][j]);
                }
            }
        }
       // return dp[0][0];
       int maxi=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          maxi=max(maxi,dp[i][j]);
        }
       }
       return maxi>=3 ? maxi:0;
    }
};