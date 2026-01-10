class Solution {
public:
unordered_map<char,int>mp;
bool helper(string s,string t){
      int n=s.size();
      int m=t.size();
      int i=0;
      int j=0;
      while(i<n&&j<m){
        if(mp[s[i]]<mp[t[j]])return true;
        if(mp[s[i]]>mp[t[j]])return false;
        i++;
        j++;
      }
      return s.size()<=t.size();
}
    bool isAlienSorted(vector<string>& words, string order) { 
        int n=words.size();
        int v=0;
        for(auto i:order){
            mp[i]=v++;
        }
        for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
                if(!helper(words[i],words[j])){
                    return false;
                }
           }
        }
        return true;
        
    }
};