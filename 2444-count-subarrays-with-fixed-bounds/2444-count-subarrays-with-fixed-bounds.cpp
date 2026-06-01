class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int n=nums.size();
        int idx1=-1;
        int idx2=-1;
        int badi=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==minK){
                idx1=i;
            }
            if(nums[i]==maxK){
                idx2=i;
            }
            if(nums[i]>maxK || nums[i]<minK){
                //ans+=max(0,min(idx1,idx2)-badi);
                     badi=i;
            }
              ans+=max(0,min(idx1,idx2)-badi);
        }
        return ans;
    }
};