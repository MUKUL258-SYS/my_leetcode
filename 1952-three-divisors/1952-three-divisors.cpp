class Solution {
public:
    bool isThree(int n) {
        if(n==1)return false;
    double d1=ceil(sqrt(n));
    double d2=floor(sqrt(n));
    if(d1!=d2)return false;
    int num=d1;
    for(int i=2;i<num;i++){
        if((num%i)==0)return false;
    }
    return true;
    }
};