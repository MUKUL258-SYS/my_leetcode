class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
       int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int s;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
           int j=i+1;
           int k=n-1;
           while(j<k){
             int total=nums[i]+nums[j]+nums[k];
             if(total>t){
                //mini=min(mini,abs(total-t));
                if(mini>abs(total-t)){
                    mini=abs(total-t);
                  s=total;
                }
                k--;
             }
             else if(total<t){
               // mini=min(mini,abs(total-t));
               if(mini>abs(total-t)){
                    mini=abs(total-t);
                  s=total;
                }
                j++;
             }
             else{
               /*ans.push_back({nums[i],nums[j],nums[k]});
               j++;
               while(nums[j]==nums[j-1]&&j<k)j++;
               */
               return total;
             }
           }
        }
        return s; 
    }
};