class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int x=*max_element(nums.begin(),nums.end());
        if(x<0)return x;
        int gmaxi=nums[0];
        int cmaxi=nums[0];

        int s=nums[0];
        for(int i=1;i<n;i++){
            cmaxi=max(nums[i],cmaxi+nums[i]);
            gmaxi=max(gmaxi,cmaxi);
            s+=nums[i];
        }
      
        int gmini=nums[0];
        int cmini=nums[0];
        for(int i=1;i<n;i++){
            cmini=min(nums[i],cmini+nums[i]);
            gmini=min(gmini,cmini);
        }
        cout<<gmaxi<<" "<<gmini<<endl;
        return max(gmaxi,s-gmini);
    }
};