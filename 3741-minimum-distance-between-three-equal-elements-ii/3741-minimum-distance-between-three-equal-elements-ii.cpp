class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int mini=INT_MAX;
        for(auto i:mp){
            if(i.second.size()<3)continue;
            vector<int>v=i.second;
           for(int j=0;j+2<v.size();j++){
            mini=min(mini,abs(v[j]-v[j+1])+abs(v[j+1]-v[j+2])+abs(v[j+2]-v[j]));
           }
        }
        int m;
       return m=mini==INT_MAX?-1:mini;
    }
};