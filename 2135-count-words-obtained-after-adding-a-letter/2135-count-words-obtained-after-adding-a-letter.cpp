class Solution {
public:
    int wordCount(vector<string>& s, vector<string>& t) {
        unordered_set<int>s1;
        int cnt=0;
        for(auto &i:s){
            int mask=0;
            for(auto j:i)mask=mask|(1<<(j-'a'));
            s1.insert(mask);
        }
        for(auto &i:t){
          int mask=0;
          for(auto &j:i){
            mask|=(1<<(j-'a'));
          }
          for(auto j:i){
            int newmask=mask^(1<<(j-'a'));
            if(s1.count(newmask)){cnt++;
               break;
            }
          }
        }
        return cnt;
    }
};