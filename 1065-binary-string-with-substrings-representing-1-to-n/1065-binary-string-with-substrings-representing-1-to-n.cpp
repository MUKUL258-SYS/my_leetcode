class Solution {
public:
    bool queryString(string S, int n) {
        while(n>0){
            auto s=bitset<32>(n--).to_string();
            if(S.find(s.substr(s.find("1")))==string::npos)
                return false;
            }
            return true;
    }
};