class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        for(int i=n-1;i>=0;i--){
            int a=num[i]-'0';
            if(a%2){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};