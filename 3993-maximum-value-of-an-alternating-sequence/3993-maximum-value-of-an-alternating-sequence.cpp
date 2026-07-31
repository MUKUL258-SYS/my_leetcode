class Solution {
public:
long long helper(int num,int s,int m){
     long long n=(num-(num/2));
        return s*(1ll)+(1ll)*(n-1)*(m-1);
}
    long long maximumValue(int num, int s, int m) {
        if(num==1)return s;
       long long ans=helper(num,s,m);
       ans=max(ans,helper(num-1,s+m,m));
       return ans;
    }
};