class Solution {
public:
    string breakPalindrome(string s) {
        int n=s.size();
        if(n==1)return "";
        bool f=false;
        for(int i=0;i<(n/2);i++){
            if(s[i]=='a'){
              continue;
            }
            else{
                s[i]='a';
                f=true;
                break;
            }
        }
    if(f)return s;
    s[n-1]='b';
    return s;
    }
};