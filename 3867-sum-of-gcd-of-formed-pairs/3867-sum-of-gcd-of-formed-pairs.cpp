class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans=0;
        long long maxi=0;
        vector<long long>vp;
        for(auto i:nums){
            maxi=max(maxi,1ll*i);
       long long value=__gcd(maxi,1ll*i);
   vp.push_back(value);
        }
    sort(vp.begin(),vp.end());
    int i=0;
    int j=vp.size()-1;
    while(i<j){
        ans+=__gcd(vp[i],vp[j]);
        i++;
        j--;
    } 
    return ans;   
    }
};