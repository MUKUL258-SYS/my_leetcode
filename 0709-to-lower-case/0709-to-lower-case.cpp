class Solution {
public:
    string toLowerCase(string s) {
        string ans="";
        for(auto i:s){
            if(i>='A'&&i<='Z')ans+=(i+32);
            else ans+=i;
        }
        return ans;
    }
};