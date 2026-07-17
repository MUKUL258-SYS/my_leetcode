class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sume=0;
        int sumo=0;
        for(int i=1;i<=(2*n);i++){
            if(i%2)sumo+=i;
            else sume+=i;
        }
        return __gcd(sumo,sume);
    }
};