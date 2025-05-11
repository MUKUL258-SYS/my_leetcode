class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        if(s==t)return true;
        return (s.find("1")!=string::npos)&&(t.find("1")!=string::npos);
    }
};