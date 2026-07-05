class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>v;
        int maxi=0;
        int cnt=1;
        int n=nums.size();
        if(k==1)return nums;
       for(int i=1;i<n;i++){
       if((nums[i]-nums[i-1])==1){
        cnt++;
       }
       else cnt=1;
       if(i+1>=k){
        if(cnt>=k){
            v.push_back(nums[i]);
        }
        else v.push_back(-1);
       }

       }
       return v;
    }
};