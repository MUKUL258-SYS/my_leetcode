class Solution {
public:
int n,m;
string s1,s2,s3;
//map<<pair<int,int>,bool>mp;
int dp[105][105];
bool dfs(int i,int j){
    if(i==n&&j==m)return true;
    if(dp[i][j]!=-1)return dp[i][j];
    bool ans=false;
    if(i<n&&s1[i]==s3[i+j]){
        ans=ans|dfs(i+1,j);
    }
    if(j<m&&s2[j]==s3[i+j]){
        ans=ans|dfs(i,j+1);
    }
    return dp[i][j]=ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size();
        m=s2.size();
        this->s1=s1;
        this->s2=s2;
        this->s3=s3;
       if(n+m!=s3.size())return false;
    if((s1+s2)==s3)return true;
    if((s2+s1)==s3)return true;
    memset(dp,-1,sizeof(dp));
    return dfs(0,0);
    }
};