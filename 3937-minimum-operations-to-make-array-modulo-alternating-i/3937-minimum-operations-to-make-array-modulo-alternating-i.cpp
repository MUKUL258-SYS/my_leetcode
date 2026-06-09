class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int  mini=INT_MAX;
        for(int i=0;i<k;i++){
             for(int j=0;j<k;j++){
                if(i==j)continue;
                int sum=0;
                for(int l=0;l<n;l++){
                    int rem=nums[l]%k;
                    if(l%2){
                      sum+=min((j-rem+k)%k,(rem-j+k)%k);
                    }
                    else {
                        sum+=min((i-rem+k)%k,(rem-i+k)%k);
                    }
                }
                mini=min(mini,sum);
            }
        }
        return mini;
    }
};