class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,int>mp;
        for(auto i:bulbs){
            mp[i]++;
        }
        vector<int>v;
        for(auto i:mp){
            int m=i.second;
    if(m%2)v.push_back(i.first);
        }
        sort(v.begin(),v.end());
        return v;
    }
};