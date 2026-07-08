class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long cnt=0;
        long long x=0;
        while(n){
            if(n%10 == 0){
                n/=10;
                continue;
            }
            sum+=(n%10);
            //sum=sum*10+(n%10);
            x+=(pow(10,cnt))*(n%10);
            n/=10;
            cnt++;
            
        }
        return sum*x;
    }
};