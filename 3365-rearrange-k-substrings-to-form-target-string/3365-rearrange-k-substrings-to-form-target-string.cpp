class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n=s.size();
        int sz=n/k;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i+=sz){
             mp[s.substr(i,sz)]++;
        }
        for(int i=0;i<n;i+=sz){
            if(mp[t.substr(i,sz)]>0){
                mp[t.substr(i,sz)]--;
                if(mp[t.substr(i,sz)]==0)mp.erase(t.substr(i,sz));
            }
            else return false;
        }
        return mp.size()==0;
    }
};