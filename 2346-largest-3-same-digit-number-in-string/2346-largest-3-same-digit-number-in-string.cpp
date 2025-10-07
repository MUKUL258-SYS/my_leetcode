class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        string s="";
        for(int i=1;i<n-1;i++){
           if((num[i-1]==num[i])&&(num[i]==num[i+1])){
            s=max(s,num.substr(i-1,3));
           }
        }
        return s;
    }
};