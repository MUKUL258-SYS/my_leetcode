class Solution {
public:
//2pointers dp/////
unordered_set<int>st;
string s;
string t;
int dp[3006][3006];
int dfs(int i,int j){
    int n=s.size();
    int m=t.size();
    if(i==n){
        if(j==m){
            return 0;
        }
        return INT_MIN;
    }
    //2 options
    if(dp[i][j]!=-1)return dp[i][j];
    int maxi=INT_MIN;
    maxi=max(maxi,st.contains(i)+dfs(i+1,j));
    if(s[i]==t[j]){
        maxi=max(maxi,dfs(i+1,j+1));
    }
    return dp[i][j]=maxi;

}
    int maxRemovals(string source, string pattern, vector<int>& tt) {
        s=source;
        t=pattern;
        if(s==t)return 0;
        for(auto i:tt){
            st.insert(i);
        }
            memset(dp, -1, sizeof(dp));
        
        return dfs(0,0);

    }
};