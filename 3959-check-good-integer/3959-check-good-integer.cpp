class Solution {
public:
    bool checkGoodInteger(int n) {
       ///vector<int>v;
       long long s1=0,s2=0;
        while(n){
            ///v.push_back(n%10);
            long long rem=n%10;
            s1+=(rem);
            s2+=(rem*rem);
            n/=10;
        }
        return (s2-s1)>=50;
    }
};