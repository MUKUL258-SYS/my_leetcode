class Solution {
public:
void helper(string &s){
   /* int carry=1;
    int i=s.size()-1;
    string res="";
    int inc=1;
    while(i>=0||carry){
           int sum=(i>=0?s[i]-'0':0)+carry;
           carry=sum/2;
           res+=((sum%2)+'0');
           i--;
    }
    return res;
    */
    int i=s.size()-1;
    while(i>=0&&s[i]=='1'){
        s[i]='0';
        i--;
    }
    if(i>=0)s[i]='1';
    else s='1'+s;
    
}

    int numSteps(string s) {
        int cnt=0;
        while(s!="1"){
            if(s.back()=='0'){
              s.pop_back();
            }
            else{
               helper(s);
            }
            cnt+=1;
        }
        return cnt;
    }
};