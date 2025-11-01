class Solution {
public:
int dp[301][9][9][9][9];
map<char,pair<int,int>>mp;
string s;
int dfs(int i,int xLeft,int yLeft,int xRight,int yRight){
   if(i>=s.size()){
    return 0;
   }
   if(dp[i][xLeft][yLeft][xRight][yRight]!=-1)return dp[i][xLeft][yLeft][xRight][yRight];
   int x=mp[s[i]].first;
   int y=mp[s[i]].second;
   int left=dfs(i+1,x,y,xRight,yRight);
   if(xLeft!=6)left+=abs(xLeft-x)+abs(yLeft-y);
   int right=dfs(i+1,xLeft,yLeft,x,y);
   if(xRight!=6)right+=abs(x-xRight)+abs(y-yRight);
   return dp[i][xLeft][yLeft][xRight][yRight]=min(left,right);
}
    int minimumDistance(string word) {
        char ch='A';
        s=word;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
             mp[ch]={i,j};
             ch++;
            }
        }
     return dfs(0,6,6,6,6);
    }
};