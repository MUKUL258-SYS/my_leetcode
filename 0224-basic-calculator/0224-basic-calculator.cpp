class Solution {
public:
int helper(string s,int& idx){
    int res=0;
    int sign=1;
    int num=0;
    for(;idx<s.size();idx++){
        char ch=s[idx];
        if(ch==' ')continue;
        else if(ch=='+'||ch=='-'){
           res+=sign*(num);
           num=0;
           sign=((ch=='+')?1:-1);
           }
        else if(ch=='('){
            res+=sign*helper(s,++idx);
        }
        else if(ch==')')break;
        else{
            num=num*10+(ch-'0');
        }
    }
    return res+sign*num;
}
    int calculate(string s) {
        int idx=0;
      return   helper(s,idx);
    }
};