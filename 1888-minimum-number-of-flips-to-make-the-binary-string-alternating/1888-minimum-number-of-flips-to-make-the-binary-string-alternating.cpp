class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s=s+s;
        int ans=s.size();
        string s1="";
        string s2="";
        int n2=s.size();
        for(int i=0;i<n2;i++){
            if(i%2==0){
                s1+='0';
                s2+='1';
            }
            else{
                s1+='1';
                s2+='0';
            }
        }
        
        int l=0;
        int d1=0;
        int d2=0;
        for(int r=0;r<n2;r++){
  if(s1[r]!=s[r])d1++;
  if(s2[r]!=s[r])d2++;
  if(r-l+1>n){
      if(s1[l]!=s[l])d1--;
      if(s2[l]!=s[l])d2--;
      l++;
  }
  if(r-l+1==n){
      ans=min(ans,d1);
      ans=min(ans,d2);
  }
        }
        return ans;
    }
};