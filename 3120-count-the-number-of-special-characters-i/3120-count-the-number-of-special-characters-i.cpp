class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>mp;
        for(auto i:word){
            mp[i]++;

        }
        int cnt=0;
        for(auto i:mp){
            char c=i.first;
            if(c>='A' && c<='Z'){
                char ch=c+32;
                if(mp[ch]>0)cnt++;
            }
            
            
        }
        return cnt;
    }
};