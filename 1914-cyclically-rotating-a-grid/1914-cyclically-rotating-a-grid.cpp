class Solution {
public:
vector<int> helper(vector<int>&v,int k){
        vector<int>res;
        int n=v.size();
        for(auto i:v)cout<<i<<" ";
        cout<<endl;
        for(int i=n-k;i<n;i++)res.push_back(v[i]);
        for(int i=0;i<n-k;i++)res.push_back(v[i]);
        for(auto i:res)cout<<i<<" ";
        cout<<endl;
        return res;
}
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int sr=0;
        int sc=0;
        int er=n-1;
        int ec=m-1;
       // int k=min(n/2,m/2);
        vector<vector<int>>vp;
        while(true){
        // si=si+l;
          //  int j=sj+l;
          if(sr>er||sc>ec)break;
          vector<int>v;
          int i=sr;
          int j=sc;
           for(i=sr;i<=er;i++){
                    v.push_back(grid[i][sc]);
           }
           // sr+=1;
            sc+=1;
            for(j=sc;j<=ec;j++){
                v.push_back(grid[er][j]);
            }
            er-=1;
            for(i=er;i>=sr;i--){
                v.push_back(grid[i][ec]);
            }
            ec-=1;
            for(int j=ec;j>=sc;j--){
                v.push_back(grid[sr][j]);
            }
            //ec-=1;
            sr+=1;
            int u=v.size();
           //int kl=k%u;
            if((k%u)==0)vp.push_back(v);
            else vp.push_back(helper(v,k%u));
           // er-=1;
           // 
           //ec-=1;
        }
          sr=0;
         sc=0;
         er=n-1;
         ec=m-1;
        int lm=0;
        while(true){
        // si=si+l;
          //  int j=sj+l;
          if(sr>er||sc>ec)break;
          vector<int>v=vp[lm++];
          int i=sr;
          int j=sc;
          int l=0;
           for(i=sr;i<=er;i++){
                    grid[i][sc]=v[l++];
           }
           // sr+=1;
            sc+=1;
            for(j=sc;j<=ec;j++){
               // (grid[i][j])=v[l++];
               grid[er][j]=v[l++];
            }
            er-=1;
            for(i=er;i>=sr;i--){
              grid[i][ec]=v[l++];
            }
            ec-=1;
            for(int j=ec;j>=sc;j--){
                //(grid[i][j])=v[l++];
                grid[sr][j]=v[l++];

            }
           // ec-=1;
           sr+=1;
          //  m++;
            
        }
        return grid;
    }
};