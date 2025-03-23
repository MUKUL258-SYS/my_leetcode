class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        bool f=false;
        for(auto i:nums){
          if(i>=0){
            f=true;
            break;
          }
        }
        if(!f)return nums.back();
        unordered_set<int>s;
        
        for(auto i:nums){
            if(i>0)s.insert(i);
        }
        int sum=0;
        for(auto i:s)sum+=i;
        return sum;
    }
};