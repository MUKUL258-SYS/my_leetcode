class Solution {
public:
int helper(vector<int>&nums){
    int n=nums.size();
    vector<int>pre(n),post(n);
    pre[0]=nums[0];
    post[n-1]=nums[n-1];
    for(int i=1;i<n;i++){
        pre[i]=gcd(pre[i-1],nums[i]);

    }
    for(int i=n-2;i>=0;i--){
        post[i]=gcd(post[i+1],nums[i]);


    }
    int cnt=0;
    for(int i=0;i+1<n;i++){
        if(nums[i+1]==0)continue;
        if(nums[i]==0){
           if(i>0 && pre[i-1]==post[i+1]){
             cnt++;
           }
           continue;
        }

        if(pre[i]==post[i+1])cnt++;
    }
    return cnt;

}
    int maxValidSplits(vector<int>& nums) {
       int n=nums.size();
       int maxi=helper(nums);
       for(int i=0;i<n;i++){
        vector<int>t=nums;
        t[i]=0;

        maxi=max(maxi,helper(t));
       } 
       return maxi;
    }
};