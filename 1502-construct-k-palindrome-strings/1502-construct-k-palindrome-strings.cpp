class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)return false;
        if(s.size()==k)return true;
        unordered_map<char,int>mp;
        for(auto i:s)mp[i]++;
        int cnto=0,cnte=0;
        for(auto i:mp){
            if((i.second)%2)cnto++;
            else cnte++;
        }
      //  if(cnto>cnte)return false;
return cnto<=k;
      //  return (cnte+cnto)>=k;
    }
};