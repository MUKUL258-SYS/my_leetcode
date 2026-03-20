class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<int>s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                s.insert(grid[i][j]);
                for(int len=1;i+2*len<n&&j-len>=0&&j+len<m;len++){
                    int sum=0;
                    for(int k=1;k<=len;k++)sum+=grid[i+k][j+k];
       for(int k=1;k<=len;k++)sum+=grid[i+len+k][j-k+len];
       for(int k=1;k<=len;k++)sum+=grid[i+2*len-k][j-k];
       for(int k=1;k<=len;k++)sum+=grid[i+len-k][j+k-len];
       s.insert(sum);


                }
            }
        }
        vector<int>v(s.rbegin(),s.rend());
        if(v.size()>3)v.resize(3);
        return v;
    }
};