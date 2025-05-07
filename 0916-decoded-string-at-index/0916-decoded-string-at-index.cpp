class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long l=0;
        int n=s.size(); 
        for(char &c:s){
            if(c>='0'&&c<='9'){
                l*=c-'0';
            }
            else{
                l++;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]>='1'&&s[i]<='9'){
                l=l/(s[i]-'0');
                k%=l;
            }
            else{
                if(k==0||(k==l))return string("")+s[i];
                l--;
            }
        }
        return "";
    }
};