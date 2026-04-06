class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        int maxi=0;
        for(int i=0;i<n;i++){
            cnt+=(nums[i]==1)?1:-1;
            if(mp.find(cnt)!=mp.end()){
                maxi=max(maxi,i-mp[cnt]);
            }
            else{
                mp[cnt]=i;
            }
        }
        return maxi;
    }
};