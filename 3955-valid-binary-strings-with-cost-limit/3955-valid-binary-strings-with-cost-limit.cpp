class Solution {
public:
vector<string>res;
int m,k;
void dfs(string s){
    if(s.size()==m){
        int cnt=0;
        //for(auto j:s)if(j=='1')cnt++;
        for(int i=0;i<s.size();i++)if(s[i]=='1')cnt+=i;
        if(cnt<=k)res.push_back(s);
        return ;
    }
    
    if(s.empty()){
        dfs(s+'0');
        dfs(s+'1');
    }
    else{
        if(s.back()=='1')dfs(s+'0');
        else{
            dfs(s+'1');
            dfs(s+'0');
        }
    }
}
    vector<string> generateValidStrings(int n, int k) {
        m=n;
        this->k=k;
         dfs("");
         return res;
    }
};