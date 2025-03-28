class Solution {
public:
int n,m;
vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
bool helper(int i,int j,vector<vector<int>>&vis){
    if(i<0||j<0||i>=n||j>=m||vis[i][j])return false;
    return true;
}
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int,int>>vp;
         n=grid.size();
         m=grid[0].size();
        int l=queries.size();
        for(int i=0;i<l;i++){
           vp.push_back({queries[i],i});
        }
        sort(vp.begin(),vp.end());
        vector<int>ans(l);
        int cnt=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    vector<vector<int>>vis(n,vector<int>(m,0));
    vis[0][0]=1;
    pq.push({grid[0][0],0,0});
        for(auto &[val,idx]:vp){
           while(pq.size()){
            auto [v,i,j]=pq.top();
            if(v>=val)break;
            pq.pop();
            cnt++;
            for(int k=0;k<4;k++){
                int ni=i+dirs[k][0];
                int nj=j+dirs[k][1];
                if(helper(ni,nj,vis)){
                    pq.push({grid[ni][nj],ni,nj});
                    vis[ni][nj]=1;
                }
            }
           }
           ans[idx]=cnt;
        }
        return ans;

    }
};