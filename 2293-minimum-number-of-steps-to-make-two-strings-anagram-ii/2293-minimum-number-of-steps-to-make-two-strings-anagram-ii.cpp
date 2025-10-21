class Solution {
public:
    int minSteps(string s, string t) {
     unordered_map<char,int>mp;
     for(auto i:s)mp[i]++;
     for(auto i:t)mp[i]--;
     int cnt=0;
     for(auto i:mp)cnt+=abs(i.second);
     return cnt;   
    }
};