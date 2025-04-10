class Solution {
public:
    bool isPrintable(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>indegree(61,0);
        vector<vector<int>>gr(61);
        for(int colr=1;colr<=60;colr++){
            int minx=n,miny=m,maxx=-1,maxy=-1;
            for(int x=0;x<n;x++){
                for(int y=0;y<m;y++){
                    if(grid[x][y]==colr){
                        minx=min(minx,x);
                        maxx=max(maxx,x);
                        miny=min(miny,y);
                        maxy=max(maxy,y);
                    }
                }
            }
            for(int x=minx;x<=maxx;x++){
                for(int y=miny;y<=maxy;y++){
                    if(grid[x][y]!=colr){
                        gr[colr].push_back(grid[x][y]);
                     indegree[grid[x][y]]++;
                    }
                }
            }
        }
            int cnt=0;
            queue<int>q;
            for(int colr=1;colr<=60;colr++){
                if(indegree[colr]==0)q.push(colr);
            }
            while(!q.empty()){
                int node=q.front();
                q.pop();
                cnt++;
                for(auto &child:gr[node]){
                    if((--indegree[child])==0){
                        q.push(child);
                    }
                }
            }
            return cnt==60;
    }
};