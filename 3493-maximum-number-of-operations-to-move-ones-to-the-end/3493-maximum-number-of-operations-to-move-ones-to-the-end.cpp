class Solution {
public:
    int maxOperations(string s) {
        vector<long long>v;
  string t=s;
  sort(t.begin(),t.end());
  if(s==t)return 0;
        int n=s.size();
        int e=n-1;
        while(e>=0&&s[e]=='1'){
            e--;
        }
        e=min(e,n-2);
        for(int i=0;i<=e;i++){
            if(s[i]=='0')continue;
            int j=i;
            long long cnt=0;
            while(j<=e&&s[j]=='1'){
                cnt++;
                j++;
            }
            v.push_back(cnt);
            i=j;


        }
        
        for(int i=1;i<v.size();i++){
            v[i]+=v[i-1];
        }
        long long sum=0;
        for(auto j:v)sum+=j;
        return sum;
    }
};