class Solution {
public:
    int minArrivalsToDiscard(vector<int>& a, int w, int m) {
        int n=a.size();
        int i=0;
        int cnt=0;
        unordered_map<int,int>mp;
        vector<int>isdiscarded(n,false);
        for(int j=0;j<n;j++){
            mp[a[j]]++;
           if(j-i+1>w){
               if(!isdiscarded[i]){
                  mp[a[i]]--;
                  if(mp[a[i]]==0)mp.erase(a[i]);
                  
               }
               i++;
           }
           if(mp[a[j]]>m){
            cnt++;
               isdiscarded[j]=true;
               mp[a[j]]--;
             if(mp[a[j]]==0)mp.erase(a[j]);
           }
        }
        return cnt;
    }
};