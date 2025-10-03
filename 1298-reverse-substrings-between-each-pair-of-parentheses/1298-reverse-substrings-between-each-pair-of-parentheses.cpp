class Solution {
public:
    string reverseParentheses(string str) {
        /*int n=str.size();
        stack<string>s;
        string temp="";
        for(auto ch:str){
            if(ch=='('){
                if(temp.size()>0)s.push(temp);
                temp="";
            }
            else if(ch==')'){
                reverse(temp.begin(),temp.end());
                string t2="";
                if(s.size()){
                    string t2=s.top();
                    s.pop();

                }
                s.push(t2+temp);
                temp="";
                
            }
            else{
                temp+=ch;
            }
           // cout<<temp<<endl;
        }
        return s.top();
        */

        vector<int>indices;
        vector<char>v;
        for(auto ch:str){
            if(ch=='('){
                indices.push_back(v.size());
            }
            else if(ch==')'){
                int last=indices.back();
                indices.pop_back();
                reverse(v.begin()+last,v.end());
            }
            else v.push_back(ch);
        }
        return string(v.begin(),v.end());
    }
};