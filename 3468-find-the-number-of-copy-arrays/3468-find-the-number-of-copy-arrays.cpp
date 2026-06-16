class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int left=bounds[0][0];
        int right=bounds[0][1];
        int res=right-left+1;
        int n=original.size();
        for(int i=1;i<n;i++){
            int diff=original[i]-original[i-1];
            left=max(left+diff,bounds[i][0]);
            right=min(right+diff,bounds[i][1]);
            res=min(res,right-left+1);
        }
        return res<0?0:res;
    }
};