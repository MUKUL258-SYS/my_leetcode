class Solution {
public:
    int numSteps(string s) {
        int carry=0;
       // int i=s.size()-1;
       int n=s.size();
        int steps=0;
       for(int i=n-1;i>0;i--){
        int digit=s[i]-'0'+carry;
        if(digit==1){
             steps+=2;
             carry=1;
        }
        else steps++;
       }
       return steps+carry;
    }
};