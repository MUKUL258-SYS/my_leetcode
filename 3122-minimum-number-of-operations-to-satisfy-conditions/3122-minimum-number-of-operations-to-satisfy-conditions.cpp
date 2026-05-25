class Solution {
public:
    
/*map<pair<int,int>,int>mk;
int n;
int m;
int dfs(int j,vector<pair<int,int>>&v,int last){
      if(j>=v.size())return 0;
      int v1=v[j].first;
      int v2=v[j].second;
      int freq1=mk[{j,v1}];
      int freq2=mk[{j,v2}];
int ans=0;
   if(v1!=last){
    ans=max(ans,m-freq1+dfs(j+1,v,v1));
   }
   if(v2!=last){
    ans=max(ans,m-freq2+dfs(j+1,v,v2));
   }
   return ans;
}
pair<int,int>helper(int j,vector<int>&nums){
    unordered_map<int,int>mp;
    for(auto i:nums){
        mp[i]++;
    }
       int maxi1 = -1, maxi2 = -1;
    int freq1 = 0,  freq2 = 0;

    for (auto& [val, freq] : mp) {
        if (freq > freq1) {
            // demote current best to second
            freq2 = freq1; maxi2 = maxi1;
            freq1 = freq;  maxi1 = val;
        } else if (freq > freq2) {
            freq2 = freq;  maxi2 = val;
        }
    }
    mk[{j,maxi1}]=freq1;
    mk[{j,maxi2}]=freq2;
    return {maxi1,maxi2};
}
    int minimumOperations(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        vector<pair<int,int>>vp;
       for(int j=0;j<m;j++){
       // unordered_map<int,int>mp;
        //vector<int>v(10,0);
         vector<int>v;
        for(int i=0;i<n;i++){
           v.push_back(grid[i][j]);
        }
        pair<int,int>res=helper(j,v);
        vp.push_back(res);
        

       }
       for(auto i:vp){
        cout<<i.first<<" "<<i.second<<endl;
       }
       return dfs(0,vp,-1);


    }
    */
   // vector<vector<int>>freq;
   //vector<vector<int>>grid;
    int freq[1000][10] = {};
    int dp[1000][11] = {};  // 11 to accommodate sentinel p=10
    int n, m;

    int dfs(int j, int p) {
        if (j >= m) return 0;
        if (dp[j][p] != 0) return dp[j][p];

        int ans = 0;
        for (int v = 0; v <= 9; v++) {
            if (v != p) {
                ans = max(ans, freq[j][v] + dfs(j + 1, v));
            }
        }

        return dp[j][p] = ans;
    }

    int minimumOperations(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int j = 0; j < m; j++)
            for (int i = 0; i < n; i++)
                ++freq[j][grid[i][j]];

        return m * n - dfs(0, 10);  // 10 = no previous column
    }
};