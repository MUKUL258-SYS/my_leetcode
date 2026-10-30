class Solution {
public:
    int maxBalancedShipments(vector<int>& w) {
        int maxi=0;
        int cnt=0,ans=0;
        for(auto i:w){
            if(i>=maxi){
                maxi=i;
                cnt++;
            }
            else{
               if(cnt>=1)ans++;
                maxi=0;
                cnt=0;
            }

        }
        return ans;
    }
};