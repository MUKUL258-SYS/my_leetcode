class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long x=100000;
        vector<int>temp;
        for(auto i:nums){
            if(i!=0)temp.push_back(i);
        }
        nums=temp;
        int n=nums.size();
         if(n<=1)return 0;
        long long p1=1LL*nums[0]*nums[1];
        long long p2=1LL*nums[n-1]*nums[n-2];
        long long p3=1LL*nums[0]*nums[n-1];
        long long maxi=0;
       
        maxi=max(maxi,abs(p1*x));
        maxi=max(maxi,abs(p2*x));
        maxi=max(maxi,abs(p3*x));
        return maxi;
    }
};