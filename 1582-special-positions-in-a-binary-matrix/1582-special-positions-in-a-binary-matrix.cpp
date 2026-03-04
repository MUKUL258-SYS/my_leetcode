class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    int cnt1=0;
                     for(int k=0;k<m;k++){
                        if(mat[i][k]==1)cnt1++;
                     }
                     int cnt2=0;
                     for(int k=0;k<n;k++){
                        if(mat[k][j]==1)cnt2++;
                     }
                    if(cnt1==1&&cnt2==1)ans++;
                }
            }
        }
        return ans;
    }
};