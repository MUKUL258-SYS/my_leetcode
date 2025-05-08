class Solution {
public:
    int monotoneIncreasingDigits(int n) {
       //base case\edges case
        if(n>=0&&n<=9)return n;
        //if(n%10==0)return n-1;
       string s=to_string(n);
       int m=s.size();
       int index=m;
       for(int i=index-1;i>0;i--){
        if(s[i-1]>s[i]){
            index=i;
            s[i-1]--;
        }
       }
       for(int i=index;i<m;i++)s[i]='9';
       return stoi(s);
    }
};