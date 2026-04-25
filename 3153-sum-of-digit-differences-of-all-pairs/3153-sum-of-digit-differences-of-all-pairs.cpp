class Solution {
public:
long long helper(map<char,int>&mp,int digits){
   /* for(auto i:mp){
        cout<<i.first<<" "<<i.second<<" ";
    }
    cout<<endl;
    */
   // int n=mp.size();
    long long ans=0;
    for(auto i:mp){
        
        digits-=(i.second);
        if(digits<0)break;
      ans+=((1ll*i.second)*digits);
    }
    return ans;
}
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans=0;
        //long long k=10;
        //int digits=to_string(nums[0]).size();
        vector<string>vp;
        for(auto i:nums){
            vp.push_back(to_string(i));
        }
        int digits=vp[0].size();
        for(int i=0;i<digits;i++){
            map<char,int>mp;
            for(auto j:vp){
               mp[j[i]]++;
            }
            ans+=helper(mp,vp.size());
        }
        return ans;
        
 
    }
};