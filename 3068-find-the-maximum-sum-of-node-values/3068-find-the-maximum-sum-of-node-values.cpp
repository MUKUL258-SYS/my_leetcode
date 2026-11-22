class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0;
        int cnt=0;
        int mini=INT_MAX;
        for(auto el:nums){
            if((el^k) > el){
                sum+=(el^k);
                mini=min(mini,(el^k)-el);
                cnt++;
            }
            else{
                sum+=el;
                mini=min(mini,el - (el^k));
            }
        }
        if(cnt%2 == 0)return sum;

        return sum-mini;
    }
};