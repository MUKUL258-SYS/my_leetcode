class Solution {
public:
int n,m;
vector<int>av,nums;
vector<vector<unordered_map<int, int>>> dp;

int dfs(int i,int j,int curr){
    if(i==n){
        if(j==m)return 0;
        return INT_MAX;
    }
    if(j>=m)return INT_MAX;
    if(n-i < m-j)return INT_MAX;
    if(dp[i][j].count(curr))return dp[i][j][curr];

    int newcurr=curr&nums[i];
    if((newcurr & av[j])!=av[j])return dp[i][j][curr]=INT_MAX;
    int op=dfs(i+1,j,newcurr);

    if(newcurr ==av[j]){
        int val=dfs(i+1,j+1,-1);
        if(val!=INT_MAX)
        op=min(op,nums[i]+val);
    }
    return dp[i][j][curr]=op;
}

    int minimumValueSum(vector<int>& nums, vector<int>& avo) {
         // n=nums.size();
         // m=av.size();
           // dp.resize(n,
          //  vector<unordered_map<int, int>>(m));

          this->nums=nums;
           av=avo;
           n=nums.size();
          m=av.size();
           dp.resize(n,
            vector<unordered_map<int, int>>(m));
          int res=dfs(0,0,-1);
          if(res==INT_MAX)return -1;
          return res;
    }
};