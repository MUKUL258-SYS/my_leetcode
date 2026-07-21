class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=nums[n-1];
        vector<int>post;
        post.push_back(maxi);
        for(int i=n-2;i>=0;i--){
       maxi=max(maxi,nums[i]);
        post.push_back(maxi);
        }
        reverse(post.begin(),post.end());
        for(auto i:post)cout<<i<<endl;
        maxi=0;
        for(int i=0;i+k<n;i++){
          maxi=max(maxi,nums[i]+post[i+k]);
        }
        return maxi;
    }
};