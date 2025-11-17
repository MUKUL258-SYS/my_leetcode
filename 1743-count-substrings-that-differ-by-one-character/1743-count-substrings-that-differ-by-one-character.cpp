class Solution {
public:
    int countSubstrings(string s, string t) {
        int n=s.size();
        int m=t.size();
        int ans=0;
        vector<vector<int>>same(n+1,vector<int>(m+1,0));
        vector<vector<int>>different(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    same[i][j]=(1+same[i-1][j-1]);
                    different[i][j]=different[i-1][j-1];
                }
                else
                    different[i][j]=1+same[i-1][j-1];
                  ans+=different[i][j];
            }
        }
        return ans;
    }
};