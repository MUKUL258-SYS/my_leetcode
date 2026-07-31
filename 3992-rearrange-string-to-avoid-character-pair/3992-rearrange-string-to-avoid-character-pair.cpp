class Solution {
public:
    string rearrangeString(string s, char x, char y) {
       // vector<int>indices;
        int n=s.size();
        vector<char>xp,yp,vp;
        for(auto i:s){
            if(i==x)xp.push_back(i);
            else if(i==y)yp.push_back(i);
            else vp.push_back(i);
        }
        string str="";
        for(auto i:yp)str+=i;
        for(auto i:vp)str+=i;
        for(auto i:xp)str+=i;
        return str;

    }
};