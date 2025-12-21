class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& vp) {
        stack<pair<int,int>> s;
        s.push({vp[0],0});
        int n=vp.size();
        vector<int> ans(n);
        for(int i=1;i<vp.size();i++){
      while(!s.empty() && vp[i]>s.top().first){
          ans[s.top().second]=i-s.top().second;
          s.pop();
      }
        s.push({vp[i],i});      
   }
   return ans;
    }
};