class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        //vector<vector<int>>gird(n*n+1);
        vector<pair<int,int>>grid((n*n)+1);
        vector<int>cols;
        for(int i=0;i<n;i++)cols.push_back(i);
        int row=n-1;
        int k=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
               grid[k++]={i,cols[j]};
            }
            reverse(cols.begin(),cols.end());
        }
        vector<int>dist((n*n)+1,-1);
        queue<int>q;
        q.push(1);
        dist[1]=0;
        while(q.size()){
            auto curr=q.front();
            q.pop();
            //auto [x,y]=grid[f];
            //int next=board[x][y]==-1?board[x][y]:-1;
   for(int next=curr+1;next<=min(n*n,curr+6);next++){
      
      pair<int,int>c=grid[next];
      int x=c.first;
      int y=c.second;
      int l=next;
      if(board[x][y]!=-1){
          l=board[x][y];
      }
      if(dist[l]==-1){
        dist[l]=1+dist[curr];
        q.push(l);
      }

       
   }

        }

        return dist[n*n];
    }
};