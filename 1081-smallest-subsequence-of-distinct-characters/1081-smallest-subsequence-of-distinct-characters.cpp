class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>last(26,0);
        int k=0;
        for(auto ch:s){
            last[ch-'a']=k;
            k++;
        }
        int n=s.size();
        stack<char>st;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            if(mp[s[i]]>0)continue;
            while(!st.empty() && s[i]<st.top() && last[st.top()-'a']>i){
                mp[st.top()]=0;
                st.pop();
              
            }
           if(mp[s[i]]==0){st.push(s[i]);
                mp[s[i]]++;
           }
        }
        string res="";
        while(st.size()){
            res+=st.top();
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};