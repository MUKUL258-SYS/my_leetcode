class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        for(auto i:answers){
            mp[i]++;
        }
        int ans=0;
        for(auto i:mp){
            int g_size=i.first+1;
            int v=ceil((double)i.second/g_size);
            v=v*g_size;
            ans+=v;
        }
        return ans;
    }
};