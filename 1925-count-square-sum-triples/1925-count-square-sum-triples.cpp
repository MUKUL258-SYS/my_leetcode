class Solution {
public:
    int countTriples(int n) {
        vector<int>v;
        unordered_map<long long,int>mp;
        for(int i=1;i<=n;i++){
            v.push_back(i);
            mp[i*i]++;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              long long value=1LL*v[i]*v[i]+1LL*v[j]*v[j];
              if(mp[value]>0){
                cnt+=2;
              }

        }
        }
        return cnt;
    }
};