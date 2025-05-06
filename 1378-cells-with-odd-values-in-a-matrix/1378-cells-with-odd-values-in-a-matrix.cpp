class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>>arr(m,vector<int>(n,0));
        for(auto i:indices){
            int x=i[0];
            int y=i[1];
            for(int j=0;j<n;j++)arr[x][j]++;
            for(int j=0;j<m;j++)arr[j][y]++;
        }
        int cnt=0;
        for(auto &i:arr){
            for(auto &j:i){
              if(j&1)cnt++;
            }
        }
        return cnt;
    }
};