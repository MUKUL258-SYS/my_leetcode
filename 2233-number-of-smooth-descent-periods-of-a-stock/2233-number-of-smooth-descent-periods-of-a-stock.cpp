class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        int n=prices.size();
        int i=0;
        int j=1;
        while(j<n){
            if(prices[j-1]-prices[j]!=1){
                long long diff=j-i;
                ans+=(diff*(diff+1))/2;
                i=j;
                j++;
            }
            else{
            while(j<n&&(prices[j-1]-prices[j])==1){
                  j++;
            }

            }
        }
        long long diff=j-i;
                ans+=(diff*(diff+1))/2;
        return ans;
    }
};