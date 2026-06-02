class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
      /*  vector<pair<int,int>>v;
        v.push_back({nums[0],0});

        for(int i=1;i<n;i++){
            int value=nums[i];
            int last_idx=v.back().second;
            if(value>v.back().first){
                int diff=i-last_idx+1;
                if(diff>=3)cnt++;
                v.push_back({value,i});
            }
            else{

            }
        }
        */
        stack<int>s;
        s.push(nums[0]);
        for(int i=1;i<n;i++){
            long long cnt=0;
            while(s.size()&&(nums[i]>s.top())){
                  cnt++;
              s.pop();
            }
            if(s.size())ans+=cnt;
            else ans+=(cnt-1);
            s.push(nums[i]);
        }
        return ans;
    }
};