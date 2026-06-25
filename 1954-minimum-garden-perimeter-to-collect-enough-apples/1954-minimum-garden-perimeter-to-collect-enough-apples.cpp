class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long s=0;
        long long e=1e5;
        long long ans=e;
        while(s<=e){
            long long n=(s+e)/2;
            long long value=2*(n)*(n+1)*(2*n+1);
            long long mid=n;
            if(value>=neededApples){
               ans=mid;
               e=mid-1;
            }
            else s=mid+1;
        }
        return 8*ans;

    }
};