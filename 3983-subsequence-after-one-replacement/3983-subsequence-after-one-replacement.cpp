class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.size();
        int i=0;
        int j=0;
        for(auto ch:t){
            if(s[i]==ch)i++;
            i=max(i,j+1);
            if(s[j]==ch)j++;
            if(i==n||j==n)return true;
        }
        return false;
    }
};