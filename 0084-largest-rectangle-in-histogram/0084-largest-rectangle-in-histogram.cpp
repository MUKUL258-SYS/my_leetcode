class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
         int n=h.size();
    stack<int>s;
    //int n=h.size();
    int ans=0;
    for(int i=0;i<=n;i++){
        while(s.size()&&(i==n||(h[s.top()]>=h[i]))){
            int idx=s.top();
            s.pop();
            int height=h[idx];
            //int width=i-s.top();
            int width;
            if(s.empty())width=i;
            else{
                width=(i-s.top()-1);
            }
      ans=max(ans,height*width);
        }
        s.push(i);
    }
    return ans;
    }
};