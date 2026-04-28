class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        stack<int>s;
        for(int i=0;i<n;i++){
           if(s.empty()||nums[s.top()]>nums[i]){
            s.push(i);
           }
        }
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            while(s.size()&&nums[i]>=nums[s.top()]){
                maxi=max(maxi,i-s.top());
                s.pop();
            }
        }
        return maxi;
    }
};