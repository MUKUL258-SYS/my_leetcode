class Solution {
public:
long long helper(long long  n,int len){
long long res=n;
    if(len%2){
        n=n/10;
    }
    while(n){
        res=res*10+(n%10);
        n=n/10;
    }
    return res;

}
    vector<long long> kthPalindrome(vector<int>& queries, int len) {
        int m=queries.size();
        vector<long long>v(m,-1);
long long s=pow(10,(len-1)/2);
long long e=pow(10,(len+1)/2);
      for(int i=0;i<m;i++){
       int ns=s+queries[i]-1;
       if(ns<e)
       v[i]=helper(ns,len);
      }
      return v;
    }
};