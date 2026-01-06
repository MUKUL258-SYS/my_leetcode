class Solution {
public:
int helper(int s,int e,string str){
        int cnt=0;
        int n=str.size();
        while(s>=0&&e<n&&str[s]==str[e]){
            cnt++;
            s--;
            e++;
        }
        return cnt;
}
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans++;
            if(i+1<n){
                ans+=helper(i,i+1,s);
            }
            if(i-1>=0&&i+1<n){
                ans+=helper(i-1,i+1,s);
            }

        }
        return ans;
    }
};