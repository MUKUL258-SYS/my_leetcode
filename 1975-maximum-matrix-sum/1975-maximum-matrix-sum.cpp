class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        vector<vector<int>>grid;
        int n=matrix.size();
        for(auto &i:matrix){
            int  cnt=0;
            vector<int>v;
            for(auto j:i){
                if(j<0)cnt++;
                v.push_back(abs(j));
            }
            sort(v.begin(),v.end());
            if(cnt%2==1)v[0]=(-1*v[0]);
            grid.push_back(v);
        }
        int cnt=0;
        vector<int>v;
        for(int i=0;i<n;i++){
           if(grid[i][0]<0)cnt++;
           v.push_back(abs(grid[i][0]));
        }
        sort(v.begin(),v.end());
   if(cnt%2==1){
    v[0]=-1*v[0];
   }
   long long sum=0;
for(auto i:v)sum+=i;
for(int i=0;i<n;i++){
    for(int j=1;j<n;j++){
        sum+=grid[i][j];
    }
}
return sum;
        
    }
};