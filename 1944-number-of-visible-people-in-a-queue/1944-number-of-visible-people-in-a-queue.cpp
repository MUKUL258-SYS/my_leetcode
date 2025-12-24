class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>s;
        int n=heights.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            int cnt=0;
         while(s.size()&&heights[i]>heights[s.top()]){
            cnt++;
            s.pop();
         }
         if(s.size())cnt++;
         ans[i]=cnt;
         s.push(i);
        }
        return ans;
        
            }
};