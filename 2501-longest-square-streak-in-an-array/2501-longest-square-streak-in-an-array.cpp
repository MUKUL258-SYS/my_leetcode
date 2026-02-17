class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
    int maxi=-1;
        for(auto i:nums){
            if(mp.count(i)){
            int cnt=0;
            long long v=i;
            while(mp[v]>0){
                cnt++;
                mp.erase(v);
                v=(v*v);
            }
        
            if(cnt>1)maxi=max(maxi,cnt);
        }

        }
        return maxi;
    }
};