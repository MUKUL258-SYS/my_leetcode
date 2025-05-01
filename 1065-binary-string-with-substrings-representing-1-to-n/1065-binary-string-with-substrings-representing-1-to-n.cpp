class Solution {
public:
string helper(int n){
    string str="";
    while(n>0){
   str+=((n%2)+'0');
   n/=2;
    }
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    return str;
}
    bool queryString(string s, int n) {
        int m=s.size();
        unordered_map<string,int>mp;
        for(int i=0;i<m;i++){
            string temp="";
            for(int j=i;j<m;j++){
                temp+=s[j];
                mp[temp]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(mp[helper(i)]>0)continue;
            return false;
            }
        return true;
    }
};