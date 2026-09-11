class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();
       vector<vector<int>>dp(n,vector<int>(m));
       unordered_map<int,vector<pair<int,int>>>mp;
       for(int i=0;i<n;i++){
           dp[i][0]=(mat[i][0]==1);
           mp[dp[i][0]].push_back({i,0});
       } 
       for(int j=0;j<m;j++){
        dp[0][j]=(mat[0][j]==1);
        mp[dp[0][j]].push_back({0,j});
       }
       for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j]==0)continue;
            dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
            mp[dp[i][j]].push_back({i,j});
        }
       }
       int ans=0;
       for(auto k:mp){
          int x=k.second.size();
          if(x<=1)continue;
          auto vp=k.second;
          int sz=k.first;
          int n=vp.size();
          for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=vp[i].first;
                int x2=vp[j].first;
                int y1=vp[i].second;
                int y2=vp[j].second;
                int d1=abs(x1-x2);
                int d2=abs(y1-y2);
                if(d1>=sz || d2>=sz){
                    ans=max(ans,sz);
                    break;
                }
            }

          }
       }

   return ans*ans;
    }
};