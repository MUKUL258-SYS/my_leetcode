class Solution {
public:
    int addDigits(int num) {
        while(true){
            if(num>=0&&num<=9)break;
            int s=0;
            while(num>0){
                s+=num%10;
                num/=10;
            }
            num=s;
        }
        return num;
    }
};