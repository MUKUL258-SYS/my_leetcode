class Solution {
public:
vector<vector<int>>v;
int val;
void dfs(int sr,int sc,int len){
    if(len==1){
        v[sr][sc]=val;
        val++;
        return ;
    }
    int mid=len/2;
    dfs(sr,sc+mid,mid);
    dfs(sr+mid,sc+mid,mid);
    dfs(sr+mid,sc,mid);
    dfs(sr,sc,mid);
}
    vector<vector<int>> specialGrid(int n) {
        int len=1<<n;
        v.resize(len,vector<int>(len,0));
        dfs(0,0,len);
        return v;
    }
};