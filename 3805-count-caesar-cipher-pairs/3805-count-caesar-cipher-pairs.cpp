class Solution {
public:
    long long countPairs(vector<string>& words) {
        set<string>s;
        //int cnt=0;
        long long ans=0;
        unordered_map<string,int>mp;
        for(auto i:words){
            if(mp[i]>0){
                int v=mp[i];
                 ans+=(1ll*v);
                 
            }
            
               for(int k=0;k<26;k++){
                string str=i;
                for(int j=0;j<str.size();j++){
                      str[j]=((str[j]-'a'+k)%26+'a');
                }
               // s.insert(str);
                mp[str]++;
            
            }

        }
       // for(auto i:s)cout<<i<<endl;
        return ans;

    }
};