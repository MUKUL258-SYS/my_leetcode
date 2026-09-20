class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
       //vector<int>v;
       int n=heights.size();
       stack<int>s;
       //s.push(heights[n]);
       vector<int>ans(n,0);
       for(int i=n-1;i>=0;i--){
        int v=0;
        while(s.size() && heights[i]>=s.top()){
            v++;
            s.pop();
        }
        if(s.size())v+=1;
        ans[i]=v;
        s.push(heights[i]);
       }
       return ans;
    }
};