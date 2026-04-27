class Solution {
public:
unordered_map<int,vector<pair<int,int>>>mp;
int n,m;
bool dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&grid){
    if(i==n-1 && j==m-1)return true;
    vis[i][j]=true;
    for(auto &dir:mp[grid[i][j]]){
        int ni=i+dir.first;
        int nj=j+dir.second;
        if(ni<0||ni>=n||nj<0||nj>=m||vis[ni][nj])continue;
        for(auto &backdir:mp[grid[ni][nj]]){
            int nii=ni+backdir.first;
            int njj=nj+backdir.second;
            if(nii==i && njj==j){
              if(dfs(ni,nj,vis,grid)){
                return true;
              }
            }
        }
       // return false;

    }
    return false;
}
    bool hasValidPath(vector<vector<int>>& grid) {
        n=grid.size();
         m=grid[0].size();
       
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        //unordered_map<int,vector<pair<int,int>>>mp;
        vis[0][0]=true;
        mp[1]={{0,-1},{0,1}};
        mp[2]={{1,0},{-1,0}};
        mp[3]={{0,-1},{1,0}};
        mp[4]={{0,1},{1,0}};
        mp[5]={{-1,0},{0,-1}};
        mp[6]={{-1,0},{0,1}};
       return dfs(0,0,vis,grid);
    }
};