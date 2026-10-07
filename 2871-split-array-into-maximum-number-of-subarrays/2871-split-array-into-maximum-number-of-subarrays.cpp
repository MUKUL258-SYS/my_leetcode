class Solution {
public:

    int maxSubarrays(vector<int>& nums) {
      int   mini=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            mini=mini&nums[i];
        }
        if(mini)return 1;
        int cnt=0;
        mini=-1;
        for(int i=0;i<n;i++){
            if(mini==0){
                cnt++;
                mini=-1;
            }
                mini=mini&nums[i];
            
        }
           
        return mini==0?cnt+1:cnt;
    }
};