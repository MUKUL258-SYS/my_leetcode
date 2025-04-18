class Solution {
public:
int helper(int n){
    int sum=0;
    int div=2;
    while(n>1){
       if(n%div==0){
        sum+=div;
        n/=div;
       }
       else div++;
    }
    return sum;
}
    int smallestValue(int n) {
        while(true){
            int s=helper(n);
            if(s==n)break;
            n=s;
        }
        return n;
    }
};