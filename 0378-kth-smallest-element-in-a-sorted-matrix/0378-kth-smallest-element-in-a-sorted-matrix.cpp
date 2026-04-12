class Solution {
public:
int n;
int helper(int mid,vector<vector<int>>&grid){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=(upper_bound(grid[i].begin(),grid[i].end(),mid)-grid[i].begin());
    }
    return cnt;
}
    int kthSmallest(vector<vector<int>>& mat, int k) {
         n=mat.size();
        int l=mat[0][0];
        int r=mat[n-1][n-1];
        int ans;
        while(l<=r){
            int mid=(l+r)/2;
            int cnt=helper(mid,mat);
            if(cnt>=k){
                ans=mid;
                r=mid-1;
            }
            else{
               l=mid+1;
            }
        }
        return ans;
        
    }
};