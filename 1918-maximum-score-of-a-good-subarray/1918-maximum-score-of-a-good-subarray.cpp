class Solution {
public:
   /* int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>vp=nums;
        for(int i=k-1;i>=0;i--){
            vp[i]=min(nums[i],vp[i+1]);
        }
        for(int i=k+1;i<n;i++){
            vp[i]=min(nums[i],vp[i-1]);
        }
        int i=k-1;
        int j=k+1;
        int maxi=0;
        while(i>=0||j<n){
            if(i>=0&&j<n){
                int v=min(vp[i],vp[j])*(j-i+1);
                maxi=max(maxi,v);
                i--;
                j++;
            }
            else if(i>=0){
                int v=vp[i]*(n-i);
                maxi=max(maxi,v);
                i--;
            }
            else if(j<n){
                int v=vp[j]*(j+1);
                maxi=max(maxi,v);
                j++;
            }
            
        }
        return maxi;
    */
    int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    int i = k, j = k;
    int min_val = nums[k], max_score = nums[k];

    while (i > 0 || j < n - 1) {
        // Expand towards the larger side to maximize the width
        if (i == 0) {
            j++;
        } else if (j == n - 1) {
            i--;
        } else if (nums[i - 1] > nums[j + 1]) {
            i--;
        } else {
            j++;
        }

        // Update the min value in the window
        min_val = min(min_val, min(nums[i], nums[j]));

        // Calculate max score
        max_score = max(max_score, min_val * (j - i + 1));
    }

    return max_score;
}
};