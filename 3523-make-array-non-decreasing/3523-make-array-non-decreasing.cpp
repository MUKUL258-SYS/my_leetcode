class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        if(temp==nums)return temp.size();
        int n=nums.size();
     stack<int>s;
     for(auto i:nums){
       // while(!s.empty()&&i)
       if(s.empty()){
        s.push(i);
        continue;
       }
       if(i<s.top())continue;
       s.push(i);
     }
     return s.size();
    }
};