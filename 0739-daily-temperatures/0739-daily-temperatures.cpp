class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int>ans(n,0);
        stack<pair<int,int>>s;
        s.push({t[0],0});
        for(int i=1;i<n;i++){
            while(!s.empty()&&t[i]>s.top().first){
                ans[s.top().second]=i-s.top().second;
                s.pop();
            }
            s.push({t[i],i});
        }
        return ans;

    }
};