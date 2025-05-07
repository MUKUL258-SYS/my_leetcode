class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        int size=1<<n;
        vector<vector<int>>grid(size,vector<int>(size));
        solver(grid,0,size,0,size);
        return grid;
    }
    int val=0;
    void solver(vector<vector<int>>&grid,int sr,int er,int sc,int ec){
        int size=er-sr;
        if(size==1){
            grid[sr][sc]=val++;
            return ;
        }
        int midrow=sr+size/2;
        int midcol=sc+size/2;
        solver(grid,sr,midrow,midcol,ec);
        solver(grid,midrow,er,midcol,ec);
        solver(grid,midrow,er,sc,midcol);
        solver(grid,sr,midrow,sc,midcol);
    }
};