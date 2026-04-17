class Solution {
public:
//2pointers dp/////
unordered_set<int>st;
string s;
string t;
int dp[3006][3006];
int NEG=INT_MIN;
int dfs(int i,int j){
    int n=s.size();
    int m=t.size();
    if(i==n){
        if(j==m){
            return 0;
        }
        return NEG;
    }
    //2 options
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=NEG;
     int take = dfs(i + 1, j);
        if (take != NEG) {
            ans = max(ans, (int)st.count(i) + take);
        }

        // OPTION 2: match pattern character
        if (j < m && s[i] == t[j]) {
            int match = dfs(i + 1, j + 1);
            if (match != NEG) {
                ans = max(ans, match);
            }
        }
    return dp[i][j]=ans;

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