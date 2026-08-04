class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int x=0;
        int cnte=0;
        int cnto=0;
        int n=nums.size();
        int maxi=0;
        map<pair<int,int>,int>mp;
        mp[{0,0}]=-1;
                for(int i=0;i<n;i++){
                    if(nums[i]%2)cnto++;
                    else cnte++;
                    x=x^nums[i];

                    pair<int,int>p={cnte-cnto,x};
                    if(mp.count(p)){
    maxi=max(maxi,i-mp[p]);
                    }
                    else mp[p]=i;
                }
                return maxi;
    }
};