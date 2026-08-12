class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      map<char,int>mp,temp;
      for(auto i:s1)mp[i]++;
      int k=s1.size();
      int n=s2.size();
      if(s1==s2)return true;
      if(k>n)return false;
      for(int i=0;i<k;i++)temp[s2[i]]++;
      if(mp==temp)return true;
      for(int i=1;i+k<=n;i++){
        temp[s2[i-1]]--;
        if(temp[s2[i-1]]==0)temp.erase(s2[i-1]);
        temp[s2[i+k-1]]++;
        if(mp==temp)return true;
      }
      return false;
    }
};