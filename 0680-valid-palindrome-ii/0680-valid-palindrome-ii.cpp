class Solution {
public:
    bool validPalindrome(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        if(s==t)return true;
        int j=s.size()-1;
        int i=0;
        while(i<=j && s[i]==s[j]){
            i++;
            j--;
        }
        
        int len=j-i;
         t=s.substr(i,len);
        string p=t;
        reverse(p.begin(),p.end());
        //cout<<t<<" "<<p<<endl;
        if(t==p)return true;
        //t=s.substr(i+1,j-i-1);
        t=s.substr(i+1,len);
        p=t;
        reverse(p.begin(),p.end());
         cout<<t<<" "<<p<<endl;
        if(t==p)return true;

        return false;
    }
};