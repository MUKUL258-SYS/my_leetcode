class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=nums[k];
        int mini=nums[k];
        int i=k-1;
        int j=k+1;
        while(i>=0&&j<n){
            if(nums[i]>=nums[j]){
                 mini=min(mini,nums[i]);
                 i--;
            }
            else{
                mini=min(mini,nums[j]);
                j++;
            }
           maxi=max(maxi,mini*(j-i-1));


        }
        while(i>=0){
            mini=min(mini,nums[i]);
              maxi=max(maxi,(j-i)*mini);
              i--;
        }
        while(j<n){
                mini=min(mini,nums[j]);
                 maxi=max(maxi,(j-i)*mini);
                 j++;
        }
        return maxi;
    }
};