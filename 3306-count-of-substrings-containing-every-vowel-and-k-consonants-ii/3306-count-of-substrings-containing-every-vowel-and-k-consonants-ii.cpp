class Solution {
public:
unordered_map<char,int>mp;
long long atleast(string word,int k){
    long long ans=0;
    int n=word.size();
    //set<char>s;
    unordered_map<char,int>freq;
    int conso=0;
    int j=0;
     //if(mp[word[i]]>0)freq[word[i]]++;
     // else conso++;
    for(int i=0;i<n;i++){
        if(mp[word[i]]>0)freq[word[i]]++;
      else conso++;
      while((j<=i) && (freq.size()==5 && conso>=k)){
        ans+=(n-i);
        if(mp[word[j]]>0){
            freq[word[j]]--;
            if(freq[word[j]]==0)freq.erase(word[j]);
        }
        else{
            conso--;
        }
        j++;

      }

     // if(mp[word[i]]>0)freq[word[i]]++;
     // else conso++;
    }
    return ans;
}
    long long countOfSubstrings(string word, int k) {
          mp['a']++;
          mp['e']++;
          mp['i']++;
          mp['o']++;
          mp['u']++;
          return (atleast(word,k)-atleast(word,k+1));
    }
};