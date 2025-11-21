class Solution {
public:
    string removeSubstring(string s, int k) {
        stack<pair<char,int>>st;
        for(char c:s){
            if(!st.empty()&&st.top().first==c){
               st.top().second++;
            }
            else{
                st.push({c,1});
            }
            if(st.size()>=2){
                auto p1=st.top();
                st.pop();
                auto p2=st.top();
                st.pop();
                if(p1.first==')'&&p1.second==k&&
                   p2.first=='('&&p2.second>=k){
                    p2.second-=k;
              if(p2.second>0)st.push(p2);
            }
                else{
                    st.push(p2);
                    st.push(p1);
                }
            }
        }
        vector<pair<char,int>>vp;
       while(!st.empty()){
           vp.push_back(st.top());
           st.pop();
       }
        reverse(vp.begin(),vp.end());
        string ans="";
        for(auto i:vp){
            int cnt=i.second;
         while(cnt--)ans+=i.first;
        }
        return ans;
    }
};