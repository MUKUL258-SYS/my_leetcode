class Solution {
public:
//nse and nge mixed
int mod=1e9+7;
    int maxSumMinProduct(vector<int>& nums) {
        stack<long long>s1;
        stack<long long>s2;
        int n=nums.size();
        vector<long long>pre(n);
        vector<long long>post(n);
        for(int i=0;i<n;i++){
            while(!s1.empty()&&nums[s1.top()]>=nums[i]){
                s1.pop();
            }
            if(s1.empty()){
                pre[i]=-1;
            }
            else{
                pre[i]=s1.top();
            }
            s1.push(i);

        }

        for(int i=n-1;i>=0;i--){
            while(!s2.empty()&& nums[i]<=nums[s2.top()]){
                s2.pop();
            }
            if(s2.empty()){
                post[i]=n;
            }
            else{
                post[i]=s2.top();
            }
            s2.push(i);
        }
        vector<long long>v(n,0);
        v[0]=1ll*nums[0];
        for(int i=1;i<n;i++){
            v[i]=v[i-1]+1ll*nums[i];
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            int idx1=pre[i]+1;
            int idx2=post[i]-1;
    long long val=1ll*nums[i]*(v[idx2]-(idx1>=1?v[idx1-1]:0));
         ans=max(ans,val);
        }
        return ans%mod;
        

    }
};