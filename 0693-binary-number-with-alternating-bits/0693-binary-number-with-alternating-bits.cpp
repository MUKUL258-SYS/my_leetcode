class Solution {
public:
    bool hasAlternatingBits(int n) {
        int n2=n;
        int prev=-1;
        while(n2){
          int rem=n2%2;
          if(prev==rem)return false;
          prev=rem;
          n2/=2;
        }
        return true;
    }
};