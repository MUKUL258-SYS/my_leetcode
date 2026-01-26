class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>>dis(n,vector<int>(n,10005));
      for(int i=0;i<n;i++){
        dis[i][i]=0;
      }
      for(auto i:edges){
        dis[i[0]][i[1]]=i[2];
        dis[i[1]][i[0]]=i[2];
      }
      for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
      }
      int mini=10005;
      int ans;
      for(int i=0;i<n;i++){
        int cnt=0;

        for(int j=0;j<n;j++){
               if(dis[i][j]<=d)cnt++;
        }
        if(cnt<mini){
            mini=cnt;
            ans=i;
        }
        else if(cnt==mini){
           // mini=min(mini,i);
           ans=max(ans,i);
        }
      }
      return ans;
    }
};