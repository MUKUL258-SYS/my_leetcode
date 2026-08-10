class Solution {
public:
bool helper(string str,int tlen){
    unordered_map<int,int>mp;
    int len=0;
    int n=str.size();
    for(int i=0;i<n;i++){
        if(i==0 || str[i]==str[i-1]){
            len++;
        }
        else{
         // mp[str[i-1]]=len-tlen+1;
            len=1;
        }
        if(len>=tlen){
            mp[str[i]-'a']++;
            if(mp[str[i]-'a']>=3){
                return true;
            }
        }

    }
    return false;


}
    int maximumLength(string s) {
       int n=s.size();
       int st=1;
       int et=n;
       int ans=-1;
       while(st<=et){
        int mid=(st+et)/2;
        if(helper(s,mid)){
            ans=max(ans,mid);
            st=mid+1;

        }
        else{
            et=mid-1;
        }
       }
       return ans;    
    }
};