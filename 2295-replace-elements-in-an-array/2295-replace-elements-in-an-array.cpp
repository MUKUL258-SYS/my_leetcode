class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {

          /*unordered_map<int,int>mp;
          for(auto i:operations){
            mp[i[0]]=i[1];
          }
          for(auto i:operations){
            int v=i[0];
            while(mp[v]>0){
              v=mp[v];
            }
          }
          */
          int n=nums.size();
          unordered_map<int,int>mp;
          for(int i=0;i<n;i++){
           mp[nums[i]]=i;
          }
          for(auto i:operations){
            int idx=mp[i[0]];
            nums[idx]=i[1];
            mp[i[1]]=idx;
          }
          return nums;
    }
};