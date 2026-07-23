class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(),coins.end());
        long long ans=0;
        long long maxi=0;
        int n=coins.size();
         long long sum=0;
        for(long long i=0,j=0;i<n;i++){

          long long window_end=coins[i][0]+k-1;
          //long long sum=0;
          while(j<n && coins[j][1]<=window_end){
            sum+=(coins[j][1]-coins[j][0]+1)*(1ll)*coins[j][2];
            j++;

          }
          long long partial=0;
          if(j<n){
        partial=max(0ll,1ll*(window_end-coins[j][0]+1));
         
        sum+=(partial*coins[j][2]);
         // maxi=max(maxi,sum);
          }
          maxi=max(maxi,sum);
          if (j < n)sum -= partial * coins[j][2];
          sum-=(coins[i][1]-coins[i][0]+1)*(1ll)*coins[i][2];
        }
        
             sum=0;
        for(long long i=n-1,j=n-1;j>=0;j--){
            long long window_start=coins[j][1]-k+1;
            while(i>=0 && coins[i][0]>=window_start){
                sum+=(1ll)*(coins[i][1]-coins[i][0]+1)*coins[i][2];
                i--;
            }
            long long  partial=0;
            if(i>=0){
              partial=max(0ll,1ll*(coins[i][1]-window_start+1));
             
              sum+=partial*(1ll)*(coins[i][2]);
              
              //  maxi=max(maxi,sum);
            }
            maxi=max(maxi,sum);
             if (i >= 0)sum -= partial * coins[i][2];
              sum-=(coins[j][1]-coins[j][0]+1)*(1ll)*coins[j][2];

        }
        return maxi;

    }
};