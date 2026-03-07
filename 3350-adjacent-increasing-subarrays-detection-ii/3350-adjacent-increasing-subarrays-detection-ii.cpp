class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
       vector<int>v;
       int cnt=1;
       int n=nums.size();
       v.resize(n,1);
       for(int i=1;i<n;i++){
        v[i-1]=cnt;
        if(nums[i]>nums[i-1]){
            cnt++;
        }
        else{
            //v[i-1]=cnt;
            cnt=1;
        }
        //v[i-1]=cnt;
       }
       v[n-1]=cnt;
       for(auto i:v)cout<<i<<" ";
       cout<<endl;
       int maxi=0;
       for(int i=0;i<n;i++){
        int len=v[i];
        if(i+len<n){
            if(v[i+len]>=v[i])maxi=max(maxi,v[i]);
        }
        if(i-len>=0){
            if(v[i-len]>=v[i])maxi=max(maxi,v[i]);
        }
       }
       return maxi;    
    }
};