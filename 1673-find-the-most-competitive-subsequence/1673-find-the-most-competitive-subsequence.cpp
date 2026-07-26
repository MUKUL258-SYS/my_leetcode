class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        int n=nums.size();
        stack<int>s;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[i]<s.top() && (n-i-1)>=(k-s.size()))s.pop();

            if(s.size()<k)s.push(nums[i]);
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};