class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int grps=0;
        vector<int>v(n,0);
        for(int i=1;i<n;i++){
          if(nums[i]-nums[i-1]<=maxDiff){
             v[i]=grps;
          }
          else {
            grps++;
            v[i]=grps;
          }
        }
        vector<bool>ans;
        for(auto i:queries){
            int un=i[0];
            int vn=i[1];
            if(v[un]==v[vn]){
              ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};