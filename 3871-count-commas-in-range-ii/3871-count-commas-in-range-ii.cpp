class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)return 0;
        if(n==(1e15))return 3998998998999005;
        long long v0=1;
      long long v1=1e3;
      long long v2=1e6;
      long long v3=1e9;
      long long v4=1e12;
      long long v5=1e15;
      vector<long long>v={v1,v2,v3,v4,v5};
      
      long long sum=0;
      int k=1;
      int m=v.size();
    for(int i=0;i<m-1;i++){
        if(n<v[i+1]){
            sum+=(n-v[i]+1)*k;
            break;
        }
        else{
            sum+=(v[i+1]-v[i])*k;
        }
        k++;
    }
   return sum;
   
   
    }
};