class Solution {
public:
    int countDigits(int num) {
        int n=num;
        int cnt=0;
        while(num>0){
            int rem=num%10;
            if(rem>0 && n%rem==0){
                cnt++;
            }
            num/=10;
        }
        return cnt;
    }
};