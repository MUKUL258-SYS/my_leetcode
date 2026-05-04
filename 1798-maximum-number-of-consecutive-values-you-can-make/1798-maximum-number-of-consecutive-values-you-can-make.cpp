class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+1>=coins[i]){
                sum+=coins[i];
            }
            else break;
        }
        return sum+1;
    }
};