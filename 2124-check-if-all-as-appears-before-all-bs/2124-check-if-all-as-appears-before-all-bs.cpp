class Solution {
public:
    bool checkString(string s) {
        int lasta=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')lasta=i;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                if(i<lasta)return false;
            }
        }
        return true;
    }
};