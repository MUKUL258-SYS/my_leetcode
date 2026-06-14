class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int>s;
        vector<int>v;
        for(auto i:nums)s.insert(i);
        int n=moveFrom.size();
        for(int i=0;i<n;i++){
            s.erase(moveFrom[i]);
            s.insert(moveTo[i]);
        }
        for(auto i:s)v.push_back(i);
        sort(v.begin(),v.end());
        return v;
    }
};