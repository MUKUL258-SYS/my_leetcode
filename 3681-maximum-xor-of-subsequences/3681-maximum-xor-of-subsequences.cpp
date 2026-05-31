class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
     int n=nums.size();
     vector<int>basis(32,0);
    for(auto &num:nums){
        for(int i=31;i>=0;i--){
            if(!(num&(1<<i)))continue;
            if(!basis[i]){
                basis[i]=num;
                break;
            }
            num=num^basis[i];
        }
    } 
    int ans=0;
   for(int i=31;i>=0;i--){
    //cout<<basis[i]<<" ";
    ans=max(ans,ans^basis[i]);
   }
    return ans; 
    }
};