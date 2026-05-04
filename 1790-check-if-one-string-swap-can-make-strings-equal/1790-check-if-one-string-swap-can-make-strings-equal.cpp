class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int cnt=0;
        string temp1="";
        string temp2="";
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]){
                continue;
            }
            temp1+=s1[i];
            temp2+=s2[i];
           cnt++;
        }
        if(cnt>2)return false;
        return ((temp1[0]==temp2[1])&&(temp1[1]==temp2[0]));
    }
};