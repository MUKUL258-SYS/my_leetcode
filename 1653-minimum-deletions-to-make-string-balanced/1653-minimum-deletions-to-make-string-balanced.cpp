class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int cnt=0;
        for(auto i:s){
            if(st.size()&&st.top()=='b'&&i=='a'){st.pop();
               cnt++;
            }
            else st.push(i);
        }
        return cnt;
    }
};