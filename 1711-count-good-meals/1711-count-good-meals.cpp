class Solution {
public:
    int countPairs(vector<int>& d) {
        unordered_map<int,int>mp;
        sort(d.begin(),d.end());
        int mod=1e9+7;
        //int  ans=0;
        for(auto i:d){
            mp[i]++;
        }
        int ans=0;
      /*  for(auto i:mp){
            int v=i.first;
            int freq=i.second;
            if((v&(v-1))==0){
             ans=(ans+(freq*(freq-1)/2)%mod)%mod;
            }
        }
        */
      //  cout<<ans<<endl;
        mp.clear();
        for(auto i:d){
           // int cnt=0;
            for(int j=0;j<=21;j++){
                int v=(1<<j);
                if(v<i)continue;
                if(mp[v-i]>0){
                    ans=(ans+mp[v-i])%mod;
                    //cout<<(v-i)<<endl;
                  //  cout<<mp[v-i]<<endl;
                }
            }
            mp[i]++;
        }
        return ans;
    }
};