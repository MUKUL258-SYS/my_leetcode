class Solution {
public:
pair<int,int> helper(int num){
    int cnt2=0;
    int cnt5=0;
    int num2=num;
    while(num2%2==0){
        cnt2++;
        num2/=2;
        

    }
    while(num%5==0){
        cnt5++;
        num/=5;
    }
    return {cnt2,cnt5};
}
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       vector<vector<pair<int,int>>>left(n,vector<pair<int,int>>(m)); 
           vector<vector<pair<int,int>>>right(n,vector<pair<int,int>>(m)); 
               vector<vector<pair<int,int>>>up(n,vector<pair<int,int>>(m)); 
                   vector<vector<pair<int,int>>>down(n,vector<pair<int,int>>(m)); 
                   for(int i=0;i<n;i++){
                    int twos=0;
                    int fives=0;
                    for(int j=0;j<m;j++){
                        left[i][j]={twos,fives};
                        pair<int,int>p=helper(grid[i][j]);
                        twos+=p.first;
                        fives+=p.second;
                    }
                   }
                   for(int i=0;i<n;i++){
                    int twos=0;
                    int fives=0;
                    for(int j=m-1;j>=0;j--){
                        right[i][j]={twos,fives};
                        pair<int,int>p=helper(grid[i][j]);
                        twos+=p.first;
                        fives+=p.second;
                    }
                   }
                   for(int j=0;j<m;j++){
                    int twos=0;
                    int fives=0;
                    for(int i=0;i<n;i++){
                        up[i][j]={twos,fives};
                        pair<int,int>p=helper(grid[i][j]);
                        twos+=p.first;
                        fives+=p.second;
                    }
                   }
                   for(int j=0;j<m;j++){
                    int twos=0;
                    int fives=0;
                    for(int i=n-1;i>=0;i--){
                        down[i][j]={twos,fives};
                        pair<int,int>p=helper(grid[i][j]);
                        twos+=p.first;
                        fives+=p.second;
                    }
                   }

              //  vector<vector<int>>v(n,vector<int>(m,0));
                int ans=0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        pair<int,int>res=helper(grid[i][j]);
                        int v1=min(up[i][j].first+left[i][j].first+res.first,up[i][j].second+left[i][j].second+res.second);
                        int v2=min(up[i][j].first+right[i][j].first+res.first,up[i][j].second+right[i][j].second+res.second);
                        int v3=min(down[i][j].first+left[i][j].first+res.first,down[i][j].second+left[i][j].second+res.second);
                        int v4=min(down[i][j].first+right[i][j].first+res.first,down[i][j].second+right[i][j].second+res.second);
                       // int mx=max()
                        ans=max(ans,max({v1,v2,v3,v4}));
                    }
                }
                return ans;


    }
};