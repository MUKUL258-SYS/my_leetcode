class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=s.size();
        string temp="";
        string ans="";
        int k=0;
        vector<string>vp;
        int m=spaces.size();
        for(int i=0;i<n;i++){
            if(k<m&&spaces[k]==i){
             ans+=temp;
             ans+=" ";
             temp="";
             k++;
            }
           temp+=s[i];
        }
        if(temp.size()>0){
            ans+=temp;
        }
        return ans;
    }
};