class Solution {
public:
    string robotWithString(string s) {
        ///decreasing monotonic stack problem 
        int n=s.size();
       /* stack<char>st;
        string res="";
        for(int i=0;i<n;i++){
            char ch=s[i];
          while(st.size()&&(ch>st.top())){
            res+=st.top();
            st.pop();
          }
          st.push(s[i]);

        }
        while(st.size()){
            res+=(st.top());
            st.pop();
        }
        return res;
        */
        vector<char>vp(n);
        vp[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
            vp[i]=min(vp[i+1],s[i]);
        }
        stack<char>st;
        string res="";
        int i=0;
         st.push(s[i]);
        for(i=1;i<n;i++){
            //st.push(s[i]);
            while(st.size()&&st.top()<=vp[i]){
               res+=st.top();
               st.pop();
            }
           st.push(s[i]);
        }

        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
        
    }
};