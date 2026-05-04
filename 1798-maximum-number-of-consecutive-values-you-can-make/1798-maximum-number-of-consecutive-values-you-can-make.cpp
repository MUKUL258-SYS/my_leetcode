class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int target=coins.back();
       
        int sum=0;
        int n=coins.size();
        for(int i=0;i<n;i++){
            if(sum+1>=coins[i]){
               sum+=coins[i];
            }
             
        }
        return sum+1;
    }
};