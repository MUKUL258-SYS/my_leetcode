class Solution {
public:
string ans;
unordered_set<string>vis;

void dfs(string s,int a,int b){
    if(vis.count(s))return;
    ans=min(ans,s);
    vis.insert(s);
    string t=s;
    int n=t.size();
    for(int i=1;i<n;i+=2){
        t[i]=(t[i]-'0'+a)%10+'0';
    }
    dfs(t,a,b);
    string newt=t.substr(n-b)+t.substr(0,n-b);
    dfs(newt,a,b);
}
    string findLexSmallestString(string s, int a, int b) {
        ans=s;
        dfs(s,a,b);
        return ans;
    }
};