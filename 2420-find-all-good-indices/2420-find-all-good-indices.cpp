class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n,0);
        vector<int>post(n,0);
        pre[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                pre[i]=pre[i-1]+1;
            }
            else{
                pre[i]=1;
            }
        }
        post[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                post[i]=post[i+1]+1;
            }
            else post[i]=1;
        }
       // for(auto i:pre)cout<<i<<" ";
       // cout<<endl;
       // for(auto i:post)cout<<i<<" ";
        vector<int>v;
        for(int i=1;i+1<n;i++){
           if(i-1>=0&&pre[i-1]>=k){
              if(i+1<n&&post[i+1]>=k)v.push_back(i);
           }

        }
        return v;
    }
};