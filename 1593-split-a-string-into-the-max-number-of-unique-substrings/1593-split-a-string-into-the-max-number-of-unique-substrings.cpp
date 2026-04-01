class Solution {
public:
//unrodered_set<string>st;
string s;
int dfs(int idx,unordered_set<string>&st){
    int n=s.size();
    if(idx>=n){
        return 0;
    }
    int cnt=0;
    
    for(int len=1;len+idx<=n;len++){
        string temp=s.substr(idx,len);
        if(st.find(temp)==st.end()){
            st.insert(temp);
        cnt=max(cnt,1+dfs(idx+len,st));
            st.erase(temp);

        }

    }
    return cnt;
}
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        this->s=s;
        return dfs(0,st);
    }
};