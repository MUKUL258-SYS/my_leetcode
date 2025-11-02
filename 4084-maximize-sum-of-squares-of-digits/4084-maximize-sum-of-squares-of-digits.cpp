class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>(9*num)||sum<1)return "";
        int f=sum/9;
        int r=sum%9;
        string res="";
        while(f--){
            res+='9';
        }
        if(r>0)res+=(r+'0');
        while(res.size()<num)res+='0';
        return res;

    }
};