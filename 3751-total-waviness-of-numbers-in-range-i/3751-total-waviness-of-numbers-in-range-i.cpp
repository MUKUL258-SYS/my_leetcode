class Solution {
public:
int helper(string s){
    int n=s.size();
    int cnt=0;
    for(int i=1;i+1<n;i++){
        if(s[i-1]<s[i]&&s[i+1]<s[i])cnt++;
        if(s[i-1]>s[i]&&s[i+1]>s[i])cnt++;
    }
    return cnt;
}
    int totalWaviness(int num1, int num2) {
        int cnt=0;
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            cnt+=helper(s);

        }
        return cnt;
    }
};