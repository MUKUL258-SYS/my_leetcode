class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            //set<int>st;
            unordered_map<char,int>mp;
            unordered_map<int,int>freq;
            for(int j=i;j<n;j++){
                int old_freq=0;
                if(mp.count(s[j]))old_freq=mp[s[j]];
              mp[s[j]]++;
              //if(freq[old_freq]==1)freq.erase(old_freq);
              //else if(freq[old_freq]>1)freq[old_freq]--;
              if(freq.count(old_freq)){
                freq[old_freq]--;
                if(freq[old_freq]==0)freq.erase(old_freq);
              }
              freq[mp[s[j]]]++;
   //  cout<<freq.size()<<endl;
              
             // st.insert(mp[s[j]]);
              if(freq.size()==1)maxi=max(maxi,j-i+1);
              //for(auto i:mp)cout<<i.first<<" "<<i.second<<" ";
            ///  cout<<endl;
            }
            //cout<<endl;
           
        }
        return maxi;
    }
};