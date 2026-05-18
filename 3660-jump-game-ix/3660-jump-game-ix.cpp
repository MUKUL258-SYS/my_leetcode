class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,0);
        vector<int>post(n,0);
        pre[0]=nums[0];
        post[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            post[i]=min(post[i+1],nums[i]);
        }
        vector<int>res(n);
        res[n-1]=pre[n-1];
        for(int i=n-2;i>=0;i--){
            if(pre[i]>post[i+1]){
                res[i]=res[i+1];
            }
            else{
                res[i]=pre[i];
            }
        }
        return res;
    }
};