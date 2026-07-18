class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& r, vector<int>& diff) {
        vector<int>ans(n,INT_MAX);
        ans[0]=0;
        for(auto i:r){
            ans[i[0]]=min(ans[i[0]],i[1]);
        }
        for(int i=1;i<n;i++){
            ans[i]=min(ans[i],diff[i-1]+ans[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            ans[i]=min(ans[i],diff[i]+ans[i+1]);
        }
        return *max_element(ans.begin(),ans.end());

    }
};