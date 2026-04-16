class Solution {
public:
int dp[600][600];
int x;
vector<int>pos;
int dfs(int l,int r){
    int m=pos.size();
    if(l>=m)return 0;
    if(r<0)return 0;
   if(l>r)return 0;
   if(dp[l][r]!=1005)return dp[l][r];
   int ans=1005;
   ans=min(ans,pos[l+1]-pos[l]+dfs(l+2,r));
   ans=min(ans,pos[r]-pos[r-1]+dfs(l,r-2));
   ans=min(ans,x+dfs(l+1,r-1));
    return dp[l][r]=ans;
}
    int minOperations(string s1, string s2, int x) {
       // vector<int>pos;
       this->x=x;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                pos.push_back(i);
            }
        }
        int n=pos.size();
        if(n%2)return -1;
        for(int i=0;i<600;i++){
            for(int j=0;j<600;j++){
                dp[i][j]=1005;
            }
        }
        return dfs(0,n-1);
    }
};