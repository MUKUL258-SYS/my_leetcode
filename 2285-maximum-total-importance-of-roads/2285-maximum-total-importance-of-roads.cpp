class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long sum=0;
        vector<int>v(n,0);
        for(auto i:roads){
          v[i[0]]++;
          v[i[1]]++;
        }
        sort(v.begin(),v.end(),greater<int>());
       // long long sum=0;
        for(auto i:v){
           sum+=(1ll*i*n);
           n--;
        }
        return sum;
    }
};