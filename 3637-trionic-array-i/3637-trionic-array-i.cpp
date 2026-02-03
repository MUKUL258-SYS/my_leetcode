class Solution {
public:
    bool isTrionic(vector<int>& nums) {
         int n=nums.size();
    for(int i=1;i<n;i++){
        if(nums[i]==nums[i-1])return false;
    }
         int cnt=0;
         vector<int>v;
         bool f1=false;
        // bool f2=false;
         for(int i=1;i+1<n;i++){
            if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]&&!f1){
                cnt++;
               // v.push_back(i);
                f1=true;

            }
         else if(nums[i]<nums[i-1]&&nums[i]<nums[i+1]){
                if(!f1)return false;

                cnt++; 
                //v.push_back(i);
                f1=false;
            }
            //else if(nums[i]<)
           // else if(nums[i]==nums[i-1])return false;
         }
         return cnt==2;
    }
};