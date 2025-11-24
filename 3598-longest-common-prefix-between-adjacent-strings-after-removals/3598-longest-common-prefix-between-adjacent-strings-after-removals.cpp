class Solution {
public:
int helper(string a,string b){
    int len=min(a.size(),b.size());
    int cnt=0;
    for(int i=0;i<len;i++){
      if(a[i]!=b[i])break;
      cnt++;
    }
    return cnt;
}
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        vector<int>ans(n,0);
        if(n<=1)return ans;
        vector<int>lcp(n-1),suff(n-1),pre(n-1);
        for(int i=0;i<n-1;i++){
            lcp[i]=helper(words[i],words[i+1]);
        }
        pre[0]=lcp[0];
        for(int i=1;i<n-1;i++){
            pre[i]=max(lcp[i],pre[i-1]);
        }
        suff[n-2]=lcp[n-2];
        for(int i=n-3;i>=0;i--){
            suff[i]=max(lcp[i],suff[i+1]);
        }
        //vector<int>ans(n,0);
        //if(n<=1)return ans;
        for(int i=0;i<n;i++){
            int best=0;
            if(i>=2)best=max(best,pre[i-2]);
            if(i+1<=n-2)best=max(best,suff[i+1]);
            if(i>0&&i<=n-2)best=max(best,helper(words[i-1],words[i+1]));
            ans[i]=best;
        }
        return ans;
    }
};