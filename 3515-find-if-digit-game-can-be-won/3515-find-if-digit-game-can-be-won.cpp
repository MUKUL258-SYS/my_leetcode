class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int s1=0;
        int s2=0;
        for(auto i:nums){
            if(i>=1&&i<=9)s1+=i;
            else s2+=i;
        }
        return s1!=s2;
    }
};