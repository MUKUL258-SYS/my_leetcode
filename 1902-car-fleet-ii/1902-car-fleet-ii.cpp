class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n=cars.size();
        vector<double>ans(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&cars[st.top()][1]>=cars[i][1]){
                st.pop();
            }

            while(!st.empty()){
            //    double c=(double)(cars[i][1]-cars[st.top()][1])/(cars[st.top()]-cars[i][0]);
            double c=(double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
                if(ans[st.top()]==-1||c<=ans[st.top()]){
                      ans[i]=c;
                      break;
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};