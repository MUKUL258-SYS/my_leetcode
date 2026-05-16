class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int>candidates;
        priority_queue<int,vector<int>,greater<int>>chosen;
        sort(queries.begin(),queries.end());
        int n=nums.size();
        int j=0;
        int m=queries.size();
        int ans=0;
        for(int i=0;i<n;i++){
            //nums[i]-=chosen.size();
            while(j<m&&queries[j][0]==i){
                candidates.push(queries[j][1]);
                j++;
            }
             nums[i]-=chosen.size();
            while(nums[i]>0&&candidates.size()>0&&candidates.top()>=i){
               ans+=1;
               nums[i]-=1;
               chosen.push(candidates.top());
               candidates.pop();
            }
            if(nums[i]>0)return -1;
            while(chosen.size()&&chosen.top()<=i){
                chosen.pop();
            }
        }
        return m-ans;
    }
};