class Solution {
public:
int helper(int i,int target,vector<int>&nums){
    unordered_map<int,int>mp;
    int sum=0;
    int n=nums.size();
    int mod=1e9+7;
    //mp[0]=1;
    int ans=0;
    for(int j=i;j<n;j++){
        if(mp[target-nums[j]]>0){
            ans=(ans+mp[target-nums[j]])%mod;
        }
        mp[nums[j]]++;
    }
    return ans%mod;
}
    int threeSumMulti(vector<int>& nums, int target) {
        int n=nums.size();
        /*vector<pair<int,int>>vp;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
              cnt++;
            }
            else{
                vp.push_back({arr[i-1],cnt});
                cnt=1;
            }
        }
        */
        int ans=0;
        int mod=1e9+7;
      for(int i=0;i<n;i++){
        int sum=target-nums[i];
        ans=(ans+helper(i+1,sum,nums))%mod;

      }
      return ans;
        


    }
};