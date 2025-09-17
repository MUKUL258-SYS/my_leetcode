class Solution {
public:
    int findTheLongestSubstring(string s) {
      unordered_map<int,int>mp;
      mp[0]=-1;
      int n=s.size();
      int pref=0;
      int ans=0;
      for(int i=0;i<n;i++){
        char ch=s[i];
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
               pref=pref^(1<<(ch-'a'));

        }
        if(mp.count(pref)){
            ans=max(ans,i-mp[pref]);
        }
        else mp[pref]=i;
      }
      return ans;
    }
};