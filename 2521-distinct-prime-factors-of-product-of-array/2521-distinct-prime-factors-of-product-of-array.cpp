class Solution {
public:
unordered_map<int,int>mp;
//vector<int>primes;
unordered_map<int,int>primes;
void seive(int maxi){
    vector<bool>vis(maxi+5,false);
   for(int i=2;i<=maxi;i++){
       if(vis[i])continue;
      //primes.push_back(i);
      //vis[i]=true;
      primes[i]++;
       for(int j=i;j<=maxi;j+=i){
          vis[j]=true;
       }
   }
}
void helper(int n){
    for(int i=2;i<=n;i++){
        if((n%i)==0 && primes[i]>0){
            mp[i]++;
           // mp[n/i]++;
        }
    }
}
    int distinctPrimeFactors(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        seive(maxi);
        for(auto i:primes){
            cout<<i.first<<endl;
        }
  for(auto i:nums){
    helper(i);
  }
  return mp.size();
    }
};