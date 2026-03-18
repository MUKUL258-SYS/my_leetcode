class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>start={1,12,123,1234,12345,123456,1234567,12345678,123456789};
        int l=log10(low)+1;
        int r=log10(high)+1;
       // cout<<l<<" "<<r<<endl;
        r=min(r,9);
        vector<int>res;
        for(int digits=l;digits<=r;digits++){
            int num=start[digits-1];
            int adder=0;
            int d=digits;
            while(d--)adder=adder*10+1;
            while(num<low&&num%10)num+=adder;
           // cout<<num<<endl;
            while(num%10&&num<=high){
                res.push_back(num);
                num+=adder;

            }
        }
        return res;
    }
};