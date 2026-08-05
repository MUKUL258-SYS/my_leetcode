class Solution {
public:
    string lastSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=1;
        int k=0;
        string ans="";
        while(j+k<n){
         if(s[j+k]==s[i+k])k++;
         else if(s[j+k]>s[i+k]){
            i=max(i+k+1,j);
            j=i+1;
            k=0;
         }
         else{
            j++;
            k=0;
         }
        }
        return s.substr(i);
    }
};