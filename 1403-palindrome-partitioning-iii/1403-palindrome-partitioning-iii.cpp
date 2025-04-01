class Solution {
public:
int n;
vector<vector<int>>dp;
int cost(string s,int i,int j){
    int c=0;
    while(i<j){
        if(s[i]!=s[j])c++;
        i++;
        j--;
    }
    return c;
}
int dfs(string&s,int idx,int p){
    if(idx>=s.size()){
        return 0;

    }
    if(p==0){
        return cost(s,idx,n-1);
    }
    if(dp[idx][p]!=-1)return dp[idx][p];
    int mini=102;
    for(int k=idx;k<n-1;k++){
       int c=cost(s,idx,k)+dfs(s,k+1,p-1);
       mini=min(mini,c);
    }
    return dp[idx][p]=mini;
}

    int palindromePartition(string s, int k) {
        n=s.size();
        dp.resize(109,vector<int>(109,-1));
        return dfs(s,0,k-1);
    }
};