class Solution {
public:
string s;
int maxi;
void dfs(int idx,unordered_map<string,int>&mp){
    int n=s.size();
    if(idx>=n){
        //maxi=max(maxi,mp.size());
        int sz=0;
        for(auto i:mp){
            sz+=i.second>0?1:0;
        }
        maxi=max(maxi,sz);
        return ;
    }
    string temp="";
    for(int j=idx;j<n;j++){
     temp+=s[j];
     if(mp[temp]>0)continue;
     mp[temp]++;
     dfs(j+1,mp);
     mp[temp]=0;
    }

}
    int maxUniqueSplit(string s) {
        unordered_map<string,int>mp;
        maxi=0;
        this->s=s;
dfs(0,mp);    
return maxi;
    }
};