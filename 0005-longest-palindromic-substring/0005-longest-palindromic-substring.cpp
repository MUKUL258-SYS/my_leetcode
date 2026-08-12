class Solution {
public:
string ans;
string s;
int maxi;
void helper(int j,int k,int cnt){
   // int cnt=0;
int ji=j;
int ki=k;
int n=s.size();
    while(ji>=0 && ki<n){
        if(s[ji]!=s[ki])break;
        cnt+=2;
        ji--;
        ki++;

    }
    if(cnt>maxi){
    maxi=cnt;
    cout<<maxi<<endl;
 //   if(ji<0)ji++;
    ans=s.substr(ji+1,maxi);
    //ans=s.substr(j,ki-ji+1);
    }


}
    string longestPalindrome(string s) {
        maxi=0;
        this->s=s;
        ans="";
        for(int i=0;i<s.size();i++){
            helper(i-1,i+1,1);
            helper(i,i+1,0);
        }
        return ans;
    }
};