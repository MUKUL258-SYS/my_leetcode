class Solution {
public:
int reverse(int n){
    int sum=0;
    while(n>0){
        sum=sum*10+(n%10);
        n/=10;
    }
    return sum;
}
    int mirrorDistance(int n) {
        int rev_num=reverse(n);
        return abs(rev_num-n);
    }
};