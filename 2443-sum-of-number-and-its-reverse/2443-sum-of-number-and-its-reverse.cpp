class Solution {
public:
int helper(int num){
    string s=to_string(num);
    string t=s;
    reverse(t.begin(),t.end());
    return stoi(t)+num;
}
    bool sumOfNumberAndReverse(int num) {
        
        for(int i=0;i<=num;i++){
            if(helper(i)==(num))return true;
        }
        return false;
    }
};