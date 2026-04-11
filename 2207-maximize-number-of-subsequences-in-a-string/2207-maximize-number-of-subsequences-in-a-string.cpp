class Solution {
public:
long long helper(string text,string p){
    int n=text.size();
    vector<int>pre(n,0);
    vector<int>post(n,0);
    int cnt=0;
    /*for(int i=0;i<n;i++){
   if(text[i]==p[0]){
    cnt++;
   }
    pre[i]=cnt;
    }
    */
    cnt=0;
    for(int i=n-1;i>=0;i--){
       // post[i]=cnt;
        if(text[i]==p[1])cnt++;
        post[i]=cnt;
    }
    long long ans=0;
    for(int i=0;i<n-1;i++){
        if(text[i]==p[0]){
     ans+=(post[i+1]);
        }
    }
    return ans;
    
}
    long long maximumSubsequenceCount(string text, string pattern) {
        long long a=helper(text+pattern[1],pattern);
        long long b=helper(pattern[0]+text,pattern);
        return max(a,b);
    }
};