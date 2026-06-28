class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& fi) {
        int n=fi.size();
       vector<unordered_set<string>>f(n);
      // int n=fi.size();
       for(int i=0;i<n;i++){
        f[i]={fi[i].begin(),fi[i].end()};
       }
       vector<int>v;
       for(int i=0;i<n;i++){
        bool flag=true;
        int m=fi[i].size();
        for(int j=0;j<n;j++){
            if(i==j||f[j].size()<f[i].size())continue;
           int cnt=0;
           for(auto &word:fi[i]){
            if(f[j].count(word))cnt++;
           }
           if(cnt == m){
            flag=false;
            break;
           }
        }
        if(flag)v.push_back(i);
       }
       return v;
    }
};