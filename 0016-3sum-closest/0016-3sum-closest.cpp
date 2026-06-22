class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int ans;
        for(int i=0;i<n;i++){
            int s=i+1;
            int e=n-1;
            int v=nums[i];
            while(s<e){
                //while(s+1<e && nums[s]==nums[s+1])s++;
               // while(s+1<e && nums[e]==nums[e-1])e--;
                int value=(nums[s]+nums[e]);
                value+=v;
                int diff=abs(value-target);
                 //mini=min(mini,abs(value-target));
                 if(diff<mini){
                    mini=diff;
                    ans=value;
                 }
                if(value==target)return value;
                else if(value>target){
                  // mini=min(mini,abs(value-target));
                  e--;}
                else{
                  //  mini=min(mini,abs(value-target));
                    s++;
                }
            }
            while(i+1<n && nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};