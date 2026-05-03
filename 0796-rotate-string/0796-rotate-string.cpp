class Solution {
public:
bool helper(int i, string s,string t){
    int j=i;
    string temp="";
    int n=s.size();
    while(j<n){
     temp+=s[j++];

    }
    j=0;
    while(j<i){
        temp+=s[j++];

    }
    return temp==t;
}
    bool rotateString(string s, string goal) {
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==goal[0]){
                if(helper(i,s,goal))return true;
            }
        }
        return false;

    }
};