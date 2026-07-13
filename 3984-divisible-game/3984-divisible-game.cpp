class Solution {
public:
static const int mod=1e9+7;
long long kadanes(vector<int>&nums,long long k){
     int n=nums.size();
        long long gmax=nums[0]%k? nums[0]*(-1) : nums[0];
        long long cmax=nums[0]%k? nums[0]*(-1) : nums[0];
        for(int i=1;i<n;i++){
            long long v=nums[i];
             if(nums[i]%k){
                v=v*(-1);
             }
            cmax=max(v,cmax+v);
            gmax=max(gmax,cmax);
        }
        return gmax%mod;
}
    int divisibleGame(vector<int>& nums) {
        /*int n=nums.size();
        int gmax=nums[0];
        int cmax=nums[0];
        for(int i=1;i<n;i++){

            cmax=max(nums[i],cmax+nums[i]);
            gmax=max(gmax,cmax);
        }
        return gmax;*/
        int maxi=1e6+1;
        long long ans=LLONG_MIN;
        long long k=2;
         set<int> st = {2}; // for all the nums like Ex.3
        

        for(auto x:nums){
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    st.insert(i);
                    while(x%i==0) x/=i;
                }
            }
            if(x>1) st.insert(x); // ex. any prime num. 7,17
        }

        for(auto i:st){
                //ans=max(ans,kadanes(nums,i));
                long long v=kadanes(nums,i);
                if(v>ans){
                    ans=v;
                    k=i;
                }
                
        }
       //return ((ans*k)%mod+mod)%mod;
       long long res = ((ans % mod) * (k % mod)) % mod;
res = ((res % mod) + mod) % mod;
return (int)res;
    }
};