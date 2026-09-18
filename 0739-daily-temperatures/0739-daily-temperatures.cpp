class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int>v(n,0);
        stack<int>s;
        
        for(int i=0;i<n;i++){
             while(!s.empty() && t[i]>t[s.top()]){
                v[s.top()]=i-s.top();
                s.pop();
             }
             s.push(i);
        }
        return v; 

    }
};