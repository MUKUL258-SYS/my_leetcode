class Solution {
public:
    int countSubstrings(string s, string t) {
        int n=s.size();
        int m=t.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x=i;
                int y=j;
                int d=0;
                while(x<n&&y<m){
                    if(s[x]!=t[y]){
                       d++;
                    }
                    if(d==1)cnt++;
                    if(d==2)break;
                    x++;
                    y++;
                }
            }
        }
        return cnt;
    }
};