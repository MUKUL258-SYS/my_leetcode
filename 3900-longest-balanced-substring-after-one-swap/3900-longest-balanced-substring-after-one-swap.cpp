class Solution {
public:
int helper(string &s){
    int n=s.size();
int count1=count(s.begin(),s.end(),'1');
int count0=n-count1;
unordered_map<int,int>mp;
mp[0]=-1;
int pre=0;
int maxi=0;
for(int i=0;i<n;i++){
    if(s[i]=='1')count1--;
    else count0--;
    pre+=s[i]=='1'?1:-1;
    if(mp.count(pre)){
  maxi=max(maxi,i-mp[pre]);
    }
    if(mp.count(pre+2)&& count1){
        maxi=max(maxi,i-mp[pre+2]);
    }
    if(mp.count(pre-2) && count0){
        maxi=max(maxi,i-mp[pre-2]);
    }
    if(!mp.count(pre)){
        mp[pre]=i;
    }

}
return maxi;
}
    int longestBalanced(string s) {
        ///approach as soon as i get more zeros inside the substring then just lok for more ones from the the index ahead of my current string 
    //10101
    //10111100
    //
   string t=s;
   reverse(t.begin(),t.end());
   return max(helper(s),helper(t));
    }
};