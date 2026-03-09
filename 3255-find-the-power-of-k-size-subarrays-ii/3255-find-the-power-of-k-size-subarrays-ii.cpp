class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int cnt=1;
        int n=nums.size();
        vector<int>v(n-k+1,-1);
        if(cnt>=k)v[0]=nums[0];
        for(int i=1;i<n;i++){
            if((nums[i]-nums[i-1])==1){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(cnt>=k){
                   v[i-k+1]=nums[i];
            }

        }
        return v;
    }
};