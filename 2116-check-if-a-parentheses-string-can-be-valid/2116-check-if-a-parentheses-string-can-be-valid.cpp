class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int>s1,s2;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                s2.push(i);
                continue;
            }
            if(s[i]=='('){
                s1.push(i);
              continue;
            }
            if(s1.size()){
                s1.pop();
            }
            else if(s2.size()){
                s2.pop();
            }
            else return false;
            
        }
        while(s1.size()&&s2.size()){
            if(s1.top()>s2.top())return false;
            s1.pop();
            s2.pop();
        }
        return s1.empty()&&((s2.size()%2)==0);
    }
};