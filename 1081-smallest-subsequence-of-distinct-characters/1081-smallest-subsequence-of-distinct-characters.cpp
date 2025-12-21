class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>last(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        vector<bool>used(26,false);
        stack<char>st;
        for(int i=0;i<n;i++){
            if(used[s[i]-'a'])continue;

            while(!st.empty()&&(st.top()>s[i])&&last[st.top()-'a']>i){
                char ch=st.top();
                used[ch-'a']=false;
                st.pop();
            }
            used[s[i]-'a']=true;
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};