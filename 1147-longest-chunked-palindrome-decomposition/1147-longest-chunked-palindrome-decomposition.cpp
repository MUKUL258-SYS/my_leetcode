class Solution {
public:
string s;
int dp[1005][1005];
int dfs(int i,int j){
   if(i>=j)return 0;
   int mid=(j-i)/2;
   if(dp[i][j]!=-1)return dp[i][j];
   cout<<mid<<endl;
   for(int len=1;len<=mid;len++){
    if(s.compare(i,len,s,j-len,len)==0){
        return 2+dfs(i+len,j-len);
    }
   }
   return dp[i][j]=1;
   
   

}
    int longestDecomposition(string text) {
       s=text;
      int n=s.size();
      for(int i=0;i<1004;i++){
        for(int j=0;j<1004;j++){
            dp[i][j]=-1;
        }
      }
     return dfs(0,n);
    }
};