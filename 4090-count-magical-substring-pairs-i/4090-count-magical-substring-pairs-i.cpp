class Solution {
public:
    int countMagicalPairs(string s) {
        int n=s.size();
        map<pair<int,int>,int>mp1,mp2;
        for(int i=0;i<n;i++){
            set<char>s1;
            for(int j=i;j>=0;j--){
             s1.insert(s[j]);
             mp1[{i,s1.size()}]++;
            }
        }
         for(int i=1;i<n;i++){
            set<char>s1;
            for(int j=i;j<n;j++){
             s1.insert(s[j]);
             mp2[{i,s1.size()}]++;
            }
        }
        int ans=0;
        for(auto m:mp1){
            auto [i,val]=m.first;
            ans+=mp2[{i+1,val}]*m.second;
        }
        return ans;
    }
};