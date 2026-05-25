class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        unordered_map<int,int>freq;
        vector<int>v;
        for(auto i:queries){
            int ball=i[0];
            int c=i[1];
            if(mp[ball]>0){
                int prev_c=mp[ball];
                freq[prev_c]--;
                if(freq[prev_c]==0)freq.erase(prev_c);
            }
            mp[ball]=c;
            freq[c]++;
            v.push_back(freq.size());
        }
        return v;
    }
};