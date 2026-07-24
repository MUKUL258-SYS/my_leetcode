class Solution {
public:
int mini;
int ta,tb,tc;
bool helper(int k,string &s){
    unordered_map<char,int>mp;
   for(int i=0;i<k;i++){
      mp[s[i]]++;
   }
   if((ta-mp['a']>=mini) && (tb-mp['b']>=mini) && (tc-mp['c']>=mini))return true;

   for(int i=1;i+k<=s.size();i++){
    mp[s[i-1]]--;
    mp[s[i+k-1]]++;
     if((ta-mp['a']>=mini) && (tb-mp['b']>=mini) && (tc-mp['c']>=mini))return true;
   }
   return false;
}
    int takeCharacters(string str, int k) {
        //string temp=str;
        //str+=temp;
        //if(str=="abc" && k==1)return 3;
        int n=str.size();
        ta=0;
        tb=0;
        tc=0;
        for(auto i:str){
            if(i=='a')ta++;
            else if(i=='b')tb++;
            else tc++;
        }
        if(ta<k || tb<k ||tc<k){
            cout<<"false";
            return -1;
        }
        mini=k;
        int s=0;
        int e=n;
        int ans=-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(helper(mid,str)){
                ans=mid;
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
        //return ans==-1?-1:n-ans;
        return n-ans;
    }
};