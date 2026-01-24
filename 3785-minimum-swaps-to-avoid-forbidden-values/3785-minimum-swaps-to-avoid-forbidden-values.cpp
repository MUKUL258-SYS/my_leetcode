class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& f) {
        map<int,int>mp,a,b;
        int n=nums.size();
        int maxi=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==f[i]){
                cnt++;
                mp[nums[i]]++;
                maxi=max(maxi,mp[nums[i]]);
            }
            a[nums[i]]++;
            b[f[i]]++;
        }
        for(auto i:a){
            if(i.second>(n-b[i.first]))return -1;
        }
        return max((cnt+1)/2,maxi);

    }
};