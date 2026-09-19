class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>s1,s2;
        vector<int>temp;
        for(int i=0;i<n;i++){
            while(s2.size() && nums[i]>nums[s2.top()]){
                ans[s2.top()]=nums[i];
                s2.pop();
            }
              vector<int>temp;
            while(s1.size() && nums[i]>nums[s1.top()]){
                temp.push_back(s1.top());
                s1.pop();
            }
            for(int k=temp.size()-1;k>=0;k--){
                s2.push(temp[k]);
            }
            s1.push(i);
        }
        return ans;

    }
};