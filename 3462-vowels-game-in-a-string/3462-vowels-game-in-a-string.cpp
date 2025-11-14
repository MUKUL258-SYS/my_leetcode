class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt=0;
        int cnt2=0;
        for(auto i:s){
            if(i=='a'||i=='e'||i=='o'||i=='i'||i=='u'){
                cnt++;
            }
            else cnt2++;
        }
        if(cnt==0)return false;
       // if((cnt%2==0)&&cnt2==0)return false;
        return true;
    }
};