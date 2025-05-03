class Solution {
public:
    int calculate(string str) {
        int n=str.size();
        stack<int>s;
        char oper='+';
        int num=0;;
        for(int i=0;i<n;i++){
            char ch=str[i];
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }

            if(!isdigit(ch)&&ch!=' '||(i==n-1)){
                if(oper=='/'){
                    int a=s.top();
                    s.pop();
                    s.push(a/num);
                }
                else if(oper=='*'){
                    int a=s.top();
                    s.pop();
                    s.push(a*num);
                }
                else if(oper=='+'){
                    s.push(num);
                }
                else if(oper=='-'){
                    s.push(-num);
                }
                oper=ch;
                num=0;
            }
        }
        int ans=0;
        while(!s.empty()){
            cout<<s.top()<<endl;
           ans+=s.top();
           s.pop();
        }
        return ans;
    }
};