class Solution {
public:
int n,m;
vector<vector<int>>heights;
void dfs(int i,int j,vector<vector<bool>>&vis){
    if(!vis[i][j])vis[i][j]=true;
    int v=heights[i][j];
    if(i-1>=0&&heights[i-1][j]>=v&&!vis[i-1][j])dfs(i-1,j,vis);
    if(j-1>=0&&heights[i][j-1]>=v&&!vis[i][j-1])dfs(i,j-1,vis);
    if(i+1<n&&heights[i+1][j]>=v&&!vis[i+1][j])dfs(i+1,j,vis);
    if(j+1<m&&heights[i][j+1]>=v&&!vis[i][j+1])dfs(i,j+1,vis);

}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        this->heights=heights;
        vector<vector<bool>>a(n,vector<bool>(m,false));
        vector<vector<bool>>b(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0)dfs(i,j,a);
                if(i==n-1||j==m-1)dfs(i,j,b);
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]&&b[i][j])ans.push_back({i,j});
            }
        }
        return ans;
    }
};