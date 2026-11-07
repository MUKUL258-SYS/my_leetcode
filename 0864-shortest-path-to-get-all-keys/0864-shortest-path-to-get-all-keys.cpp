class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       int dx[]={0,0,-1,1};
       int dy[]={-1,1,0,0};
        int totalkeys=0;
        int sx,sy;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch=grid[i][j];
                if(ch>='a' && ch<='z'){
                    totalkeys++;
                }
                if(ch=='@')sx=i,sy=j;
            }
        }
        queue<array<int,4>>q;
        q.push({sx,sy,0,0});
        vector<vector<vector<bool>>>vis(n,vector<vector<bool>>(m,vector<bool>(1<<totalkeys,false)));
       vis[sx][sy][0]=true;
       int  target=(1<<totalkeys)-1;
        while(!q.empty()){
            auto [x,y,mask,dist]=q.front();
            q.pop();
            if(mask==target)return dist;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]=='#')continue;
                char c=grid[nx][ny];
                int nmask=mask;
                if(c>='a' && c<='z'){
                     nmask=nmask|(1<<(c-'a'));

                }
                if(c>='A' && c<='Z' && !(mask&(1<<(c-'A')))){
                    continue;

                }
                if(vis[nx][ny][nmask])continue;
                vis[nx][ny][nmask]=true;
                q.push({nx,ny,nmask,dist+1});

            }

        }
        return -1;


    }
};