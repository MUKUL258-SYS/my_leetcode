class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char,int>mp;
        int cnt=0;
        for(auto i:s){
            if(mp[i]==0){
               cnt++;
            }
            mp[i]++;
        }
        return cnt;
    }
};