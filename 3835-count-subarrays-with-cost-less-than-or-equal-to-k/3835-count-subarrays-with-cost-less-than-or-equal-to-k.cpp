class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        set<pair<long long,int>>s;
        int n=nums.size();
            long long ans=0;
        
        int i=0;
        for(int j=0;j<n;j++){
            s.insert({nums[j],j});
            //int maxi=(*s.rbegin()).first;
            //int mini=(*s.begin()).first;
            while(!s.empty()&&i<=j){
                if(((*s.rbegin()).first-(*s.begin()).first)*(j-i+1) <=k)break;
                s.erase({nums[i],i});
                i++;
            }
            //int maxi=(*s.rbegin()).first;
            //int mini=(*s.begin()).first;
            //long long cost=1ll*(maxi-mini)*(j-i+1);
           /* if(cost<=k){
                long long len=(j-i+1);
                 ans+=len;
            }
            */
             long long len=(j-i+1);
                 ans+=len;
        }
        return ans;


    }
};