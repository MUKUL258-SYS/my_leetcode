class Solution {
public:
string s,t;
int n,m;
int dp[1005][1005];
vector<int>post1,post2;
int dfs(int i,int j){
    n=s.size();
    m=t.size();
    if(i==n&&j==m)return 0;
    if(i==n)return post2[j];
    if(j==m)return post1[i];
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
    if(s[i]==t[j]){
       ans=dfs(i+1,j+1);
    }
    else{
        int op1=(int)s[i]+dfs(i+1,j);
        int op2=(int)t[j]+dfs(i,j+1);
        int op3=(int)s[i]+(int)t[j]+dfs(i+1,j+1);
        ans=min({op1,op2});
    }
    return dp[i][j]=ans;
}
    int minimumDeleteSum(string s1, string s2) {
        s=s1;
        t=s2;
        n=s1.size();
        m=s2.size();
     //   vector<int>post1(s.size(),0);
       // vector<int>post2(t.size(),0);
       post1.resize(n+1,0);
       post2.resize(m+1,0);
       // post1[s.size()-1]=s.back();
       // post2[t.size()-1]=t.back();
        for(int i=n-1;i>=0;i--)post1[i]=((int)s1[i]+post1[i+1]);
         for(int i=m-1;i>=0;i--)post2[i]=((int)s2[i]+post2[i+1]);
         memset(dp,-1,sizeof(dp));
         return dfs(0,0);

    }
};