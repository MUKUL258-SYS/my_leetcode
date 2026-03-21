class Solution {
public:
    int longestContinuousSubstring(string s) {
        int maxi=1;
        int n=s.size();
        if(n==1)return 1;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]-s[i-1]==1){
              cnt++;
            }
            else{
                maxi=max(maxi,cnt);
                cnt=1;
            }
           // cout<<cnt<<endl;
        }

        if(s[n-1]-s[n-2]==1){
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};