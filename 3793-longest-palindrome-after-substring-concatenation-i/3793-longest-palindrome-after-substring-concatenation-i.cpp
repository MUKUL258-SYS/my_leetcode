class Solution {
public:
bool ispalindrome(string& s){
     for(int i = 0; i < s.size()/2; ++i){
            if(s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    /*string t=s;
    reverse(t.begin(),t.end());
    return s==t;
    */
}
    int longestPalindrome(string s, string t) {
        int n=s.size();
        int m=t.size();
        int ans=1;
        for(int i=0;i<n;i++){
             for(int l=0;l<=n;l++){
                 string temp=s.substr(i,l);
                 for(int j=0;j<m;j++){
                    for(int ll=0;ll<=m;ll++){
                        string temp2=temp+t.substr(j,ll);
                        if(ispalindrome(temp2)&&temp2.size()>ans)ans=temp2.size();
                    }
                 }
            }
        
        }
        return ans;
           
    }
};