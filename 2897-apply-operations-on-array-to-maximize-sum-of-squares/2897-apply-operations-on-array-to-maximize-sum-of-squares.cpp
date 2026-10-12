class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int>v(32,0);
        for(auto i:nums){
          int k=0;
            while(i){
              if(i%2)v[k]++;
              i=i/2;
              k++;
            }
        }
      //  for(auto i:v)cout<<i<<" ";
       // cout<<endl; 
        int sum=0;
        int mod=1e9+7;
       while(k--){
        int n=0;
        for(int i=0;i<32;i++){
            if(v[i]>0){
                n=n+pow(2,i);
                v[i]--;
            }
        }
       // cout<<n<<endl;
        sum=(sum+(1ll*n*n)%mod)%mod;
       }
       return sum;
       
    }
};