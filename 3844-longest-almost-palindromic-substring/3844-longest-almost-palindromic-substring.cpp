class Solution {
public:
int ispal(string &s,int i,int j){
    int n=s.size();
    while(i>=0&&j<n&&s[i]==s[j]){
      i--;
      j++;
    }
    return j-i-1;
}
int helper(int i,int j,string &s){
    int n=s.size();
    while(i>=0&&j<n&&s[i]==s[j]){
      i--;
      j++;
    }
   int best=j-i-1;
   if(i>=0||j<n)
    best =max(best,max(ispal(s,i-1,j),ispal(s,i,j+1)));
    return best;
}
    int almostPalindromic(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
         maxi=max(maxi,helper(i,i,s));
         maxi=max(maxi,helper(i,i+1,s));

        }
        return maxi;
    }
};