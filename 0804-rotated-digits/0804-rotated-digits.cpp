class Solution {
public:
int checker(int n){
      int cnt=0;
    while(n>0){
        int a=n%10;
        if(a==3||a==4||a==7)return 0;
        else if(a==6||a==9||a==2||a==5)cnt++;
        n/=10;
    } 
    return cnt;    
}
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(checker(i))cnt++;
        }
        return cnt;    
    }

};