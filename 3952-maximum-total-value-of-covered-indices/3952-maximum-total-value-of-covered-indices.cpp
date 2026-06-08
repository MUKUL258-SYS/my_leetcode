class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long ans=0;
        int n=nums.size();
        long long mini=LLONG_MAX;
        for(int i=n-1;i>=0;i--){
            mini=min(mini,(long long)nums[i]);
            if(s[i]=='1'){
                ans+=nums[i];
            }
            else{
              if(i+1<n && s[i+1]=='1'){  
              ans+=nums[i];
              ans-=mini;
             // mini=INT_MAX;
              }
               mini=INT_MAX;
            }
        }
        return ans;

    }
};