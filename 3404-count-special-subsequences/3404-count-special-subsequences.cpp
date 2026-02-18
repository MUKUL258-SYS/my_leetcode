class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        unordered_map<double,int>mp;
        for(int i=2;i<n;i++){
            for(int j=i-2;j>=0;j--){
               double d=double(nums[j])/double(nums[i]);
               mp[d]++;   
            }
            int r=i+2;
            for(int s=r+2;s<n;s++){
                double d=double(nums[s])/double(nums[r]);
                //if(mp.find(d)!=mp.end()){
                    ans+=mp[d];
                //}
            }
           // return ans;

        }
         return ans;

    }
};