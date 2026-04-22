class Solution {
public:
bool checker(string &s,string &t){
    int diff=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]!=t[i])diff++;
    }
    return diff<=2;

}
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        int n=queries.size();
        int m=dict.size();
        vector<string>res;
        for(int i=0;i<n;i++){
    bool f=false;
            for(int j=0;j<m;j++){
              bool ans=checker(queries[i],dict[j]);
              if(ans){
                res.push_back(queries[i]);
                f=true;
              }
              if(f)break;
            }
        }
        return res;
    }
};