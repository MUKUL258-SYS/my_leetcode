class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        vector<int>last(30,-1);
        for(int i=n-1;i>=0;i--){
           unsigned long long x=nums[i];
            bitset<30>X(x);
            int maxi=i;
            for(int k=0;k<30;k++){
                if(X[k]){
                    last[k]=i;
                }
                maxi=max(maxi,last[k]);

            }
            ans[i]=maxi-i+1;
        }
        return ans;
    }
};