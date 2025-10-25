class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int maxi=0;
        for(auto i:mp)maxi=max(maxi,i.second);
        vector<vector<int>>res(maxi);
        for(auto i:mp){
            int s=i.second;
            int k=0;
            while(s--){
          res[k].push_back(i.first);
          k++;
            }
        }
        return res;
    }
};