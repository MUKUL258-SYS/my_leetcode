class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(auto i:word1)mp1[i]++;
        for(auto i:word2)mp2[i]++;
        for(auto& [key1,val1]:mp1){
            for(auto& [key2,val2]:mp2){
                mp1[key2]++;
                mp2[key1]++;
                int n=mp1.size();
                int m=mp2.size();
               // int val1=mp1[key1];
               // int val2=mp2[key2];
                if(val1==1)n--;
                if(val2==1)m--;
                if(n==m)return true;
                mp1[key2]--;
                if(mp1[key2]==0)mp1.erase(key2);
                mp2[key1]--;
                if(mp2[key1]==0)mp2.erase(key1);
            }
            //return false;
        }
          return false;
    }
};