class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //stack<int>s;
        int n=nums.size();
       for(int i=0;i<n;i++)nums.push_back(nums[i]);
        vector<int>v(n,-1);
        stack<int>s;
       for(int i=0;i<nums.size();i++){
            while(s.size() && nums[i]>nums[s.top()]){
               if(s.top()<n)v[s.top()]=nums[i];
               s.pop();
            }
            s.push(i);
        }
        return v;
    }
};