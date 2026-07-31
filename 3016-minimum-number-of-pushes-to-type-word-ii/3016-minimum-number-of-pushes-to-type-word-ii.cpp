class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        vector<pair<int,char>>v;
        unordered_map<char,int>mp;
        for(auto i:word)mp[i]++;
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),greater<pair<int,char>>());
        int cnt=0;
        int level=1;
        long long res=0;
        for(auto p:v){
            if(cnt==8)level++,cnt=0;
            res=res+level*(p.first);
            cnt++;
        }
        return res;
    }
};