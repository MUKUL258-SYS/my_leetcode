
class Solution {
public:
    int countCollisions(string dir) {
        int n=dir.size();
        stack<char>s; 
        int ans=0;
        for(auto i:dir){
            if(s.size()&&s.top()=='R'&&i=='L'){
                s.pop();
                s.push('S');
                ans+=2;
            }
            else if(s.size()&&s.top()=='R'&&i=='S'){
                s.pop();
                s.push('S');
                ans++;
            }
              else if(s.size()&&s.top()=='S'&&i=='L'){
                s.pop();
                s.push('S');
                ans++;
            }
            else s.push(i);
        }
        while(s.size()&&s.top()=='R')s.pop();
        while(s.size()){
            if(s.top()=='R'){
                ans++;
               // s.pop();
            }
            s.pop();
        }
        return ans;

    }
};