class Solution {
public:
int mod=1e9+7;
long long helper(int n){
    long long res=1;
    while(n){
        res=(res*n)%mod;
        n--;
    }
    return res;
}

    int countPermutations(vector<int>& c) {
       unordered_map<int,int>mp;
       int maxi=0;
       int mini=INT_MAX;
       for(auto i:c){
        mp[i]++;
        maxi=max(maxi,i);
        mini=min(mini,i);
       }
       if(mp[c[0]]>1||mini!=c[0])return 0;
       return helper(c.size()-1);
       
    }
};