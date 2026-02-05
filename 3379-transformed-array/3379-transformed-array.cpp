class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>vp;
        int idx=0;
        for(auto i:nums){
           int steps=i;
           if(steps==0)vp.push_back(i);
           else if(steps<0){
            steps=abs(steps);
            steps=steps%n;
            if(idx-steps>=0){
                vp.push_back(nums[idx-steps]);
            }
            else{
                vp.push_back(nums[n+idx-steps]);
            }

           }
           else{
            steps=steps%n;
            if(idx+steps>=n){
                vp.push_back(nums[(idx+steps)%n]);
            }
            else{
                vp.push_back(nums[idx+steps]); 
           }
        }
        idx++;
        }
        return vp;
    }
};