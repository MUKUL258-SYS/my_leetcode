class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<string,int>mp;
        mp["qwertyuiop"]=1;
        mp["asdfghjkl"]=2;
        mp["zxcvbnm"]=3;
        map<char,int>mp2;
        for(auto i:mp){
           for(auto j:i.first){
            mp2[j]=i.second;
           }
        }
        for(auto i:mp2){
            cout<<i.first<<" "<<i.second<<endl;
        }
        vector<string>v;
        for(auto i:words){
          set<int>s;
          for(auto j:i){
            if(j>='A'&&j<='Z')j+=32;
            s.insert(mp2[j]);
          }
          if(s.size()==1){
            v.push_back(i);
          }
        }
        return v;
    }
};