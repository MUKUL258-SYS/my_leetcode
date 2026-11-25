class Solution {
public:
bool helper(int k,vector<int>&nums){
    unordered_map<long long,int>mp;
     long long b = 215215;
     int n=nums.size();
        long long p=1;
        long long h=0;
        long long mod = (1LL << 31)- 1;
    
    for(int i=0;i<k;i++){
        h=(h*b + nums[i])%mod;
        p=(p*b)%mod;
    }
    mp[h]++;
    for(int i=k;i<n;i++){
        h=((h*b +nums[i])-(nums[i-k]*p)%mod+mod)%mod;
        mp[h]++;
    }
    for(auto i:mp){
        if(i.second==1)return true;
    }
    return false;
    //return mp.size()==(n-k+1);
}
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int s=1;
        int e=n;
        int ans=n;
        while(s<=e){
            int mid=(s+e)/2;
            if(helper(mid,nums)){
                ans=min(ans,mid);
                e=mid-1;
            }
            else{
              s=mid+1;
            }
        }
        return ans;
    }
};