class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
       // long long ans=1;
       // for(auto i:nums)ans=ans*i;
       int maxi=0;
        for(int i=0;i<n;i++){
          unsigned  long long prod=nums[i];
          unsigned  long long g=nums[i];
          unsigned  long long l=nums[i];
            for(int j=i+1;j<n;j++){
               prod=prod*nums[j];
               l=std::lcm(l,(1ll)*nums[j]);
               g=std::gcd(g,(1ll)*nums[j]);
               if(prod==(l*g)){
                maxi=max(maxi,j-i+1);
               }
            }
        }
        return maxi;
        
    }
};