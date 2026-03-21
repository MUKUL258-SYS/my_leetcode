class Solution {
public:
bool isPal(int i,int j,string s){
    while(i<j){
        if(s[i]==s[j]){
            i++;
            j--;
        }
        else break;
    }
    return i>=j;
}
bool checker(string a,string b){
    int i=0;
    int j=a.size()-1;
    while(i<j){
        if(a[i]==b[j]){
            i++;
            j--;
        }
        else break;
    }
    if(isPal(i,j,a)||isPal(i,j,b))return true;
    return false;
}
    bool checkPalindromeFormation(string a, string b) {
        return checker(a,b)||checker(b,a);
    }
};