class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto &word:words){
            int sz=word.size();
            if(sz<k)continue;
          mp[word.substr(0,k)]++;
        }
        int cnt=0;
        for(auto i:mp){
             if(i.second>=2)cnt++;
        }
        return cnt;
    }
};