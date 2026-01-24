class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            set<int>s;
            int sum=0;
            for(int j=i;j<n;j++){
                s.insert(nums[j]);
                sum+=nums[j];
                if(s.count(sum))cnt++;
            }
        }
        return cnt;
    }
};