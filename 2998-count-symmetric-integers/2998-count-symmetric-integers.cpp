class Solution {
public:


    int countSymmetricIntegers(int l, int high) {
        int cnt=0;
        int i=l;
       while(i<=high){
        int low=i;
        if(low>=10&&low<=99){
               if((low%10)==(low/10))cnt++;
        }
        else if(low>=1000&&low<=9999){
            int a=low%10;
            low=low/10;
            int b=low%10;
            low=low/10;
            int c=low%10;
            low/=10;
            int d=low%10;
        if(a+b==c+d)cnt++;
        }
           

            i++;
       } 
       return cnt;
    }
};