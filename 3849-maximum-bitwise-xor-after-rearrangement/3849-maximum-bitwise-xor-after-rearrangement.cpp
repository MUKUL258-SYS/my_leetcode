class Solution {
public:
    string maximumXor(string s, string t) {
        int cnt0=0;
        int cnt1=0;
        for(auto i:t){
            if(i=='0')cnt0++;
            else cnt1++;
        }
        string res="";
        for(auto i:s){
            if(i=='0'){
                if(cnt1>0)res+='1';
                else res+='0';
                cnt1--;
            }
            else{
                if(cnt0>0)res+='1';
                else res+='0';
                cnt0--;
            }

        }
        return res;

    }
};