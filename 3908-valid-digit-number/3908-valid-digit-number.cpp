class Solution {
public:
    bool validDigit(int n, int x) {
        if(n==0){
            return false;
        }
        vector<int>v;
        unordered_map<int,int>mp;
        while(n){
            v.push_back(n%10);
            mp[n%10]++;
            n=n/10;
        }
        reverse(v.begin(),v.end());
        if(v[0]!=x&&mp[x]>0)return true;
        return false;
    }
};