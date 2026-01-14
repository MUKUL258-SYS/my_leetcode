class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
       int n=nums.size();
       int val=0;
       vector<bool>v(n,false);
       int k=0;
       for(auto ele:nums){
        val=(val*2+ele)%5;
        if(val==0)v[k]=true;
        k++;
       }
       return v; 

    }
};