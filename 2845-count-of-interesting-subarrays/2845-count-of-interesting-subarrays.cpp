class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<long long,long long>mp;
        vector<int>vp;
        for(auto i:nums){
  int v=((i%modulo)==k)?1:0;
  vp.push_back(v);
        }
        for(auto i:vp)cout<<i<<" ";
        cout<<endl;
        long long sum=0;
        mp[0]++;
        long long res=0;
      /*  for(int i=0;i<vp.size();i++){
           sum+=vp[i];
           //res+=mp[sum-module];
         if(mp[sum-k]>0)res+=(mp[sum-k]);
           mp[sum]++;

        }
        */
        for(auto i:vp){
            sum+=i;
            long long curr=sum%modulo;
            long long need=(curr-k+modulo)%modulo;
            if(mp.count(need)){
                res+=mp[need];
            }
            mp[curr]++;
        }
        return res;
    }
};