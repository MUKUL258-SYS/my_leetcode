class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        if(n==1)return 0;
        int m=n/2;
        string str1="";
        string str2="";
        while(m--){
            str1+='1';
            str1+='0';
            str2+='0';
            str2+='1';
        }
        if(n%2){
            if(str1.size()&&str1.back()=='1')str1+='0';
            else str1+='1';
            if(str2.size()&&str2.back()=='0')str2+='1';
            else str2+='0';
        }

        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(str1[i]!=s[i])cnt1++;
            if(str2[i]!=s[i])cnt2++;
        }
        return min(cnt1,cnt2);

    }
};