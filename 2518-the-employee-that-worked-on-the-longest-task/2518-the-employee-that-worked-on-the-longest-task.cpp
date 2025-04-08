class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int s=0;
        int m=logs.size();
        int maxi=logs[0][1];
        int mini=logs[0][0];
        for(int i=1;i<m;i++){
            int v=logs[i][1]-logs[i-1][1];
            if(v>maxi){
              maxi=v;
              mini=logs[i][0];
            }
            else if(v==maxi){
              mini=min(mini,logs[i][0]);
            }
        }
        return mini;
    }
};