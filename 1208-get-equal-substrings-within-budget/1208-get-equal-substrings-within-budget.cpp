class Solution {
public:
int maxi;
bool helper(int len,string s,string t){
    int n=s.size();
int costs=0;
    for(int i=0;i<len;i++){
        costs+=abs(s[i]-t[i]);
    }
    if(costs<=maxi)return true;
    for(int i=1;i+len<=n;i++){
        costs-=(abs(s[i-1]-t[i-1]));
        costs+=(abs(s[i+len-1]-t[i+len-1]));
         if(costs<=maxi)return true;
    }
    return false;
}
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int l=0;
        int r=n;
        maxi=maxCost;
        int ans=0;
        while(l<=r){
            int  mid=(l+r)/2;
            if(helper(mid,s,t)){
                ans=max(ans,mid);
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};