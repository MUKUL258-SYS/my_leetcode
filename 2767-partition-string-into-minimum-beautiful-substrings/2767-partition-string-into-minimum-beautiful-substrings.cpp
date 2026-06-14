class Solution {
public:
int helper(int num){
    if(num==1)return 1;
    while(num>0){
        if(num==1)break;
        if(num%5)return 0;
        num/=5;
    }
    return num==1;
}
int dfs(string s,int t=0){
    if(t>=s.size()){
        return 0;
    }
    int mini=INT_MAX;
    int num=0;
    for(int i=t;i<s.size();i++){
        num=(num<<1)+(s[i]-'0');
        if(num==0)break;
        if(helper(num)){
            int parts=dfs(s,i+1);
            if(parts!=-1)
            mini=min(mini,parts+1);
        }
    }
    return mini==INT_MAX?-1:mini;
}
    int minimumBeautifulSubstrings(string s) {
     return dfs(s);   
    }
};