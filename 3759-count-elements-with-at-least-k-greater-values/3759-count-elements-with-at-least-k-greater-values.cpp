class Solution {
public:
    int countElements(vector<int>& nums, int k) {
       // sort(nums.begin(),nums.end());
       int m=nums.size();
        map<long long,long long>mp;
        for(auto i:nums)mp[i]++;
        vector<long long>pre;
        for(auto i:mp){
            pre.push_back(i.second);
        }
        int n=pre.size();
        vector<int>temp(n,0);
        temp[n-1]=pre[n-1];
        for(int i=n-2;i>=0;i--){
            temp[i]=pre[i]+temp[i+1];
        }
       // int n=pre.size();
       if(k==0){
        return m;
       }
        long long cnt=0;
       for(int i=0;i<n-1;i++){
           if(temp[i+1]>=k)cnt+=pre[i];
       }
       return cnt;

    }
};