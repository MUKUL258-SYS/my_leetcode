class Solution {
public:
    int minOperations(int n) {
        int res=1;
        while(res*2<=n){
            res=res*2;
        }
        int h=res*2;
        if(res==n)return 1;
        return 1+minOperations(min(n-res,h-n));

    }
};