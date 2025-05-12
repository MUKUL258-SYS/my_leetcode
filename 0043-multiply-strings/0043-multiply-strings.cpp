class Solution {
public:
    string multiply(string a, string b) {
        if(a=="0"||b=="0")return "0";
        
        int n=a.size();
        int m=b.size();
        string ans(n+m,'0');
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
            int num=(a[i]-'0')*(b[j]-'0')+ans[i+j+1]-'0';
            ans[i+j+1]=(num%10)+'0';
            ans[i+j]+=num/10;
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0')return ans.substr(i);
        }
        return "0";
    }
};