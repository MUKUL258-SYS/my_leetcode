class Solution {
public:
int helper(char ch,char prev){
    int diff=abs(ch-prev);
    return min(diff,10-diff);
}
    int minRotations(int n, string s) {
        vector<int>pre(n,0),post(n,0);
        char prev='0';
        int ans=0;
        for(int i=0;i<n;i++){
             ans+=helper(s[i],prev);
             pre[i]=ans;
             prev=s[i];
        }
        prev='0';
        ans=0;
        for(int i=n-1;i>=0;i--){
           ans+=helper(s[i],prev);
        post[i]=ans;
           prev=s[i];
        }
       // for(auto i:pre)cout<<i<<" ";
      //  cout<<endl;
      //  for(auto i:post)cout<<i<<" ";
      //  cout<<endl;
        int mini=INT_MAX;
        int extra=helper(s[n-1],'0');
        for(int i=0;i<n;i++){
            int res=0;
            res+=(i>=1)?pre[i-1]:0;
            //if(i+1<n)res+=post[i+1];
            res+=post[i];
            if(i>=1){
            res+=(helper(s[i-1],s[n-1]));
            res-=extra;
            }

            mini=min(mini,res);
        }
        return mini;

    }
};