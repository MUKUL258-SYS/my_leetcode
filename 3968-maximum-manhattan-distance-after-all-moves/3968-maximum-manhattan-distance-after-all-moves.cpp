class Solution {
public:
    int maxDistance(string moves) {
        //int maxi=0;
        int ans=0;
        int cnt=0;
        unordered_map<char,int>mp;
        for(auto i:moves){
            if(i=='_')cnt++;
            else{
                mp[i]++;
            }
        }
        ans+=(max(mp['L'],mp['R'])-min(mp['L'],mp['R']));
         ans+=(max(mp['U'],mp['D'])-min(mp['U'],mp['D']));
         return ans+cnt;
    }
};