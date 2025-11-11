class Solution {
public:
    int minOperations(vector<int>& nums) {

       //// increasing subsequence problem;
       stack<int> s;
       int res=0;
       for(auto i:nums){ 
       // if(i==0)continue;           
        while(!s.empty()&&s.top()>i){
            s.pop();
        }
         if(i==0)continue;
        if(s.empty()||s.top()<i){
         res++;
        s.push(i);
        }
 }
 return res;
    }
};