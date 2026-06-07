class Solution {
public:
    bool consecutiveSetBits(int n) {
        int last=0;
        int cnt=0;
        while(n){
            int bit=n%2;
            if(bit==1 && last==1)cnt++;
            if(cnt>1)return false;
            last=bit;
            n/=2;
        }
        return cnt==1;
    }
};