class Solution {
public:
string ans;
bool dfs(vector<char>&path,vector<int>&cnt,string &target,bool b){
    int n=target.size();
    if(!ans.empty())return true ;
    if(path.size()==n){
        if(b){
        ans=string(path.begin(),path.end());
        return true;
        }
        return false;
    }
    int i=path.size();
    for(int ch=0;ch<26;ch++){
        if(cnt[ch]==0)continue;
        if(!b&&ch+'a'<target[i])continue;
        path.push_back(ch+'a');
        cnt[ch]--;
        bool newb=b||(ch+'a'>target[i]);
      if(dfs(path,cnt,target,newb))return true;
      path.pop_back();
      cnt[ch]++;
    }
    return false;
}
    string lexGreaterPermutation(string s, string target) {
        vector<int>cnt(26,0);
        for(char ch:s)cnt[ch-'a']++;
        vector<char>path;
        dfs(path,cnt,target,false);
        return ans;
    }
};