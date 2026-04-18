class Solution {
public:
int n,m;
vector<vector<int>>l;
bool checker(int row,int left,int r){
    return l[row][r]<left;
}
int bfs(int row,int col){
    int l=col;
    int r=col;
    int h=0;
    int rows=row;
    while(true){
        l--;
        r++;
        rows++;
        if(l<0||r>=m||rows>=n)break;
        if(!checker(rows,l,r))break;
        h++;


    }
    return h;
}
int bfsi(int row,int col){
    int l=col;
    int r=col;
    int h=0;
    int rows=row;
    while(true){
        l--;
        r++;
        rows--;
        if(l<0||r>=m||rows<0)break;
        if(!checker(rows,l,r))break;
        h++;


    }
    return h;
}
    int countPyramids(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
    l.resize(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        int last=-1;
        for(int j=0;j<m;j++){
            if(grid[i][j]==0)last=j;
            l[i][j]=last;
        }

    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
         if(grid[i][j]==1){
            ans+=bfs(i,j);
            ans+=bfsi(i,j);
         }
        }
    }
    return ans;

    }
};