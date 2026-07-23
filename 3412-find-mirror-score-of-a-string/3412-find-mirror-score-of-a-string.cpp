class Solution {
public:
    long long calculateScore(string s) {
        long long ans=0;
        //unordered_map<char,int>mp;
        vector<stack<int>>v(26);
        for(int i=0;i<26;i++){
            v[i]=stack<int>();
        }
        int n=s.size();
        for(int i=0;i<n;i++){
           // cout<<mirror+'a'<<" "<<s[i]<<endl;
            int mirror='z'-s[i];
            char ch='a'+mirror;
              cout<<ch<<" "<<s[i]<<endl;
           if(v[mirror].size()>0){
               ans+=(i-v[mirror].top());
               v[mirror].pop();
           }
          else  v[s[i]-'a'].push(i);
        }
        return ans;
    }
};