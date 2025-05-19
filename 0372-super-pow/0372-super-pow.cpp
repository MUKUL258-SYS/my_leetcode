class Solution {
public:
const int mod=1337;
int pow(int a,int b){
    int res=1;
    a%=mod;
    for(int i=0;i<b;i++){
        res=(res*a)%mod;
    }
    return res;

}
    int superPow(int a, vector<int>& b) {
        int res=1;
        for(int i=b.size()-1;i>=0;i--){
            res=(res*pow(a,b[i]))%mod;
            a=pow(a,10);
        }
        return res;

    }
};