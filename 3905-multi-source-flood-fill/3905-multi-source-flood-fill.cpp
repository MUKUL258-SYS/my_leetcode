class Solution {
public:
int n;
int m;
  vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
  
bool checker(int i,int j,vector<vector<bool>>&vis){
   if(i<0||i>=n||j<0||j>=m||vis[i][j])return false;
   return true;
}
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& v) {
        this->n=n;
        this->m=m;
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
           vector<vector<int>>grid(n,vector<int>(m,0));
      ///  priority_queue<vector<int>>pq;
      queue<pair<int,int>>q;
       sort(v.begin(),v.end(),[&](const vector<int> &a,const vector<int>&b){
        return a[2]>b[2];
       });
       for(auto i:v){
        cout<<i[0]<<i[1]<<i[2]<<endl;
       }
        for(auto &i:v){
            int row=i[0];
            int col=i[1];
            int val=i[2];
              vis[row][col]=true;
              grid[row][col]=val;
              //pq.push({val,row,col});
              q.push({row,col});

        }
       vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
           int sz=q.size();
           while(sz--){
            auto v=q.front();
            int i=v.first;
            int j=v.second;
            q.pop();
            for(auto dir:dirs){
                int ni=i+dir[0];
                int nj=j+dir[1];
                if(checker(ni,nj,vis)){
                    vis[ni][nj]=true;
                    grid[ni][nj]=grid[i][j];
                    q.push({ni,nj});
                }
            }


           }

        
        
    }
      return grid;
    }
};