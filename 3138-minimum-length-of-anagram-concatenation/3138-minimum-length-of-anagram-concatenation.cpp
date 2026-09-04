class Solution {
public:
bool helper(string s,int k){
    int n=s.size();
    map<char,int>mp;
    for(int i=0;i<k;i++)mp[s[i]]++;
    map<char,int>temp;
    for(int i=k;i<n;i+=k){
        for(int j=i;j<(i+k);j++){
           temp[s[j]]++;
        }
        if(temp!=mp)return false;
        temp.clear();
    }
    return true;
}
    int minAnagramLength(string s) {
    int n=s.size();
    for(int i=1;i<=n;i++){
        if((n%i)==0){
            if(helper(s,i))return i;
        }
    }
    return n;
    }
};