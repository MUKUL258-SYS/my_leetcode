class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int mod=1e9+7;
        for(auto i:q){
          int s=i[0];
          int e=i[1];
          int k=i[2];
          int v=i[3];
          for(int i=s;i<=e;i+=k){
               nums[i]=(1ll*nums[i]*v)%mod;
          }
        }
        int x=0;
        for(auto i:nums){
            x=x^i;
        }
        return x;

    }
};