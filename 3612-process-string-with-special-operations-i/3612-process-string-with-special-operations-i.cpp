class Solution {
public:
    string processStr(string s) {
        string res="";
        string t;
        for(auto ch:s){
            if(ch=='*'){
                if(t.size()>0)t.pop_back();
                
            }
            else if(ch=='#'){
                t+=t;
            }
            else if(ch=='%'){
                reverse(t.begin(),t.end());
            }
            else t+=ch;
        }
         return t;
    }
    
};