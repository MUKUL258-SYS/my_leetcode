class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       int mini=INT_MAX;
       int maxi=INT_MIN;
       unordered_map<int,int>mp;
       vector<int>v;
       for(auto i:nums){
      mp[i]++;
        mini=min(mini,i);
        maxi=max(maxi,i);
       } 
       for(int i=mini;i<=maxi;i++){
        if(mp[i]==0)v.push_back(i);
       }
       return v;
    }
};