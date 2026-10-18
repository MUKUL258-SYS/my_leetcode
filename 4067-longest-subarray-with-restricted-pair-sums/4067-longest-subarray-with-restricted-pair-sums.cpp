class Solution {
public:
int helper(vector<int>&nums,int l,int r){
    //unordered_map<int,int>mp;
    vector<int>mp(501,0);
    for(int i=l;i<=r;i++)mp[nums[i]]++;
    for(int i=1;i<=500;i++){
        if(mp[i]==0)continue;
        mp[i]--;
        for(int j=i;j<=500;j++){
            if(mp[j]==0)continue;
            mp[j]--;
            int sum=i+j;
            if(sum<=500 && mp[sum]>0)return true;
            mp[j]++;
        }
        mp[i]++;
    }
    return false;
}
    int maxSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++){
            while(l<=r && helper(nums,l,r)){
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};