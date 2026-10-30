class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        for(auto &ch:s){
            if(st.size()==0){
                st.push(ch);
                continue;
            }
            char c=st.top();
            if((c=='a' && ch=='z')  ||(ch=='a' && c=='z')){
                st.pop();
            }
            else if(abs(c-ch)==1){
                st.pop();
            }
            else st.push(ch);
        }
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;

    }
};