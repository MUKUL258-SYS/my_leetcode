class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        if(mp.size()<=k)return 0;

        vector<int>v;
        for(auto i:mp){
            v.push_back(i.second);
        }
        sort(v.begin(),v.end());
        int c=0,cnt=0;
        int n=v.size();
        for(auto i:v){
            c++;
            cnt+=i;
            if(n-c<=k)return cnt;

        }
        return -1;
        
    }
};