class Solution {
public:
vector<string>v;
void dfs(int idx,string s){
    int n=s.size();
    if(idx>=n){
     v.push_back(s);
     return ;
    }
    char ch=s[idx];
    if(ch>='0'&&ch<='9'){dfs(idx+1,s);
      return;
    }
  dfs(idx+1,s);
 if(ch>='a'&&ch<='z'){
    s[idx]-=32;
 }
 else s[idx]+=32;
 dfs(idx+1,s);
}
    vector<string> letterCasePermutation(string s) {
           dfs(0,s);
           return v;
    }
};