class Solution {
public:
int x;
int helper(vector<int>&vp,int v){
    int cnt=0;
    for(auto i:vp){
   int value=abs(i-v);
   cnt+=(value/x);

    }
    return cnt;
}
    int minOperations(vector<vector<int>>& grid, int x) {
    int n=grid.size();
    int m=grid[0].size();
    
   this->x=x;
    vector<int>v;
    if(n==1&&m==1)return 0;
    int mod=grid[0][0]%x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]%x!=mod)return -1;
            v.push_back(grid[i][j]);
        }
    }
    sort(v.begin(),v.end());
     n=v.size();
    if(n%2||n==1){
        return helper(v,v[n/2]);
    }
    return min(helper(v,v[n/2]),helper(v,v[(n-1)/2]));
    }
};