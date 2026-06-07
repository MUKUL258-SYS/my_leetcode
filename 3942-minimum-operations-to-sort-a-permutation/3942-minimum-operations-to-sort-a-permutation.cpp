class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int pos0=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                pos0=i;
                break;
            }
        }
        bool inc=true;
        bool dec=true;
        for(int i=0;i<n;i++){
            if(nums[(pos0+i)%n]!=i){
                inc=false;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[(pos0+i)%n]!=(n-i)%n){
                dec=false;
                break;
            }
        }
        if(!inc && !dec)return -1;
        int ans=INT_MAX;
        if(inc){
            ans=min(ans,min(pos0,n-pos0+2));
        }
        if(dec){
            ans=min(ans,min(pos0+2,n-pos0));
        }
        return ans;
    }
};