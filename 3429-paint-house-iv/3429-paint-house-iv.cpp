class Solution {
public:
int n;
vector<vector<int>>c;
long long dp[100005][5][5];
long long dfs(int i,int left_color,int right_color){
    if(i>=(n/2))return 0;
    if(dp[i][left_color+1][right_color+1]!=-1)return dp[i][left_color+1][right_color+1];
    int right_idx=n-i-1;
    long long mini=1e18;
    for(int c1=0;c1<3;c1++){
        for(int c2=0;c2<3;c2++){
            if(c1==c2)continue;
            if(i>0 && c1==left_color)continue;
            if(i>0 && c2==right_color)continue;
          int ans=c[i][c1]+c[right_idx][c2];
          mini=min(mini,ans+dfs(i+1,c1,c2));
        }
    }
    return dp[i][left_color+1][right_color+1]=mini;

}
    long long minCost(int n, vector<vector<int>>& cost) {
        this->n=n;
       c=cost;
       memset(dp,-1,sizeof(dp));
       return dfs(0,-1,-1);
    }
};