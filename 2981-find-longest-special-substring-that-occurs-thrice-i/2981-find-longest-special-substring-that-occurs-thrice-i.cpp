class Solution {
public:
bool helper(int len,int freq,string s){
   int n=s.size();
   unordered_map<string,int>mp;
   for(int i=0;i<n;i++){
        mp[s.substr(i,len)]++;
   }
   for(auto i:mp){
    if(i.second<3)continue;
    set<char>st;
    for(auto j:i.first){
        st.insert(j);
    }
    if(st.size()==1)return true;
   }
   return false;
}
    int maximumLength(string s) {
        int n=s.size();
        int l=1;
        int r=n;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(helper(mid,3,s)){
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