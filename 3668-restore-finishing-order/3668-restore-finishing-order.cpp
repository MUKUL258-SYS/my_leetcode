class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
       unordered_map<int,int>mp;
       for(auto i:friends)mp[i]++;
       vector<int>v;
       for(auto i:order){
        if(mp[i]>0)v.push_back(i);
       } 
       return v;
    }
};