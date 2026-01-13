class Solution {
public:
int n;
vector<string>ans;
void dfs(int i,string s,vector<string>&v){
    if(i>=n){
        if(v.size()==4){
           string res=v[0]+"."+v[1]+"."+v[2]+"."+v[3];
           ans.push_back(res); 
        }
        return ;
    }
    string temp="";
    for(int j=i;j<=min(n-1,i+2);j++){
        //if(s[j]=='0')continue;
         temp+=s[j];
         if(stoi(temp)>255)break;
         if(temp.size()>1&&temp[0]=='0')continue;
         v.push_back(temp);
         dfs(j+1,s,v);
         v.pop_back();
    }
}
    vector<string> restoreIpAddresses(string s) {
        n=s.size();
        vector<string>vp;
        dfs(0,s,vp);
        return ans;
    }
};