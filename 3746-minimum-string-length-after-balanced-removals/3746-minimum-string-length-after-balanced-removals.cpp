class Solution {
public:
    int minLengthAfterRemovals(string s) {
        unordered_map<char,int>mp;
        for(auto i:s)mp[i]++;
        int n=s.size();
        return n-2*min(mp['a'],mp['b']);
    }
};