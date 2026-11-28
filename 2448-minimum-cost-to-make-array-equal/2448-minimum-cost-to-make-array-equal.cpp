class Solution {
public:
vector<int>nums,cost;
long long helper(int v){
    long long res=0;
    for(int i=0;i<nums.size();i++){
        res=res+(1ll*abs(v-nums[i])*cost[i]);
    }
    return res;
}
    long long minCost(vector<int>& nums, vector<int>& cost) {
        this->nums=nums;
        this->cost=cost;
        long long ans=LLONG_MAX;
        long long mini=*min_element(nums.begin(),nums.end());
        long long maxi=*max_element(nums.begin(),nums.end());
        while(mini<=maxi){
            long long  mid=(mini+maxi)/2;
            long long c1=helper(mid);
            long long c2=helper(mid+1);
            if(c1<=c2){
                ans=min(ans,c1);
                maxi=mid-1;
            }
            else{
                mini=mid+1;
            }
            
        }
        return ans;
    }
};