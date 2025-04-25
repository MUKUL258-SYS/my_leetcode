class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n=nums.size();
        int m=divisors.size();
        int maxi=0;
        int res=divisors[0];
        for(auto i:divisors){
            int cnt=0;
            for(auto j:nums){
                if(j%i==0)cnt++;
            }
            if(cnt>maxi){
                maxi=cnt;
           res=i;
            }
            else if(cnt==maxi&&res>i){
                res=i;
            }
        }
        return res;
    }
};