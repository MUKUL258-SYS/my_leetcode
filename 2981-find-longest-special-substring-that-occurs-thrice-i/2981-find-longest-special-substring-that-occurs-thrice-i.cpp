class Solution {
public:
bool helper(int len,int freq,string s){
   int n=s.size();
   int clen=0;
   unordered_map<char,int>mp;
  for(int i=0;i<n;i++){
    if(i==0 || s[i]==s[i-1]){
       clen++;
    }
    else{
        clen=1;
    }
    if(clen>=len){
      mp[s[i]]++;
      if(mp[s[i]]>=3)return true;
    }
  }
  return false;
}
    int maximumLength(string s) {
        int n=s.size();
        int l=1;
        int r=n;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(helper(mid,3,s)){
                ans=max(ans,mid);
                 l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};