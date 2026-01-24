class Solution {
public:
    int residuePrefixes(string s) {
        int n=s.size();
        set<char>st;
        int cnt=0;
        for(int i=0;i<n;i++){
         st.insert(s[i]);
         int len=(i+1)%3;
         if(st.size()==len)cnt++;
        }
        return cnt;
    }
};