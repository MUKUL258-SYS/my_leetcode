class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
        string temp="";
        string res=s;
        for(int i=0;i<n;i++){
           temp+=s[i];
           string t=temp;
           reverse(t.begin(),t.end());
          res=min(res,t+s.substr(i+1));
        }
        temp="";
        for(int i=n-1;i>=0;i--){
             temp+=s[i];
          res=min(res,s.substr(0,i)+temp);
        }
        return res;
    }
};