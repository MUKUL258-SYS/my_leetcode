class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto i:s)mp[i]++;
        int cnt_odds=0;
        int res=0;
        for(auto i:mp){
            res=res+((i.second)%2==0?i.second:i.second-1);
            if((i.second)%2)cnt_odds++;
        }
        if(cnt_odds)res++;
        return res;
    }
};