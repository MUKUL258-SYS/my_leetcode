class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>post(n);
        vector<int>v(n);
        pre[0]=nums[0];
        post[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            post[i]=post[i+1]+nums[i];
        }
        for(int i=0;i<n;i++){
            int res=0;
            if(i+1<n){
             res+=abs(post[i+1]-nums[i]*(n-i-1));
            }
            if(i-1>=0){
                res+=abs((nums[i]*i)-pre[i-1]);
            }
        v[i]=res;
        }
        return v;

    }
};