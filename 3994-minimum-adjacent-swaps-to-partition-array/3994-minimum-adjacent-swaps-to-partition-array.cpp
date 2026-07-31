class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n=nums.size();
        for(auto &i:nums){
           if(i>b)i=2;
           else if(i<a)i=0;
           else{
            i=1;
           }
        }
        int cnt1=0;
        int cnt2=0;
        int swaps=0;
        int mod=1e9+7;
        for(auto i:nums){
            if(i==0){
                swaps=(swaps+(cnt1+cnt2))%mod;

            }else if(i==1){
                swaps=(swaps+(cnt2))%mod;
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        return swaps;

    }
};