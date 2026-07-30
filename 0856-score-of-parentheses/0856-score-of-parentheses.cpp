class Solution {
public:
    int scoreOfParentheses(string s) {
        int res=0;
        stack<int>st;
        for(auto ch:s){
            if(ch=='(')st.push(-1);
            else{
                if(st.top()==-1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int sum=0;
                    while(st.size() && st.top()!=-1){
                        sum+=(st.top());
                        st.pop();
                    }
                    st.pop();
                    st.push(2*sum);
                }
            }
        }
        while(st.size()){
            res+=(st.top());
            st.pop();
        }
        return res;

    }
};