class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
      //  string str="";
        long long sum=0;
          int mod=1e9+7;
        vector<long long>pref_count(n);
        vector<long long>pre(n,0);
        vector<long long>pre_s(n);
         vector<long long> pow10(n + 1);   // powers of 10 modulo mod

        // pow10
        pow10[0] = 1;
        for (int i = 1; i <= n; ++i) pow10[i] = (pow10[i-1] * 10) % mod;
        pre[0]=s[0]-'0';
        //string str="";
        pre_s[0]=s[0]-'0';
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
               pre[i]=pre[i-1];
               pre_s[i]=pre_s[i-1];
               pref_count[i]=pref_count[i-1];
            }
            else{
            pre[i]=(s[i]-'0')+pre[i-1];
            pre_s[i]=(pre_s[i-1]*10+(s[i]-'0'))%mod;
            pref_count[i]=pref_count[i-1]+1;
            }

        }
        int m=queries.size();
        for(auto i:pre_s)cout<<i<<" ";
        cout<<endl;
     //   vector<int>res(m);
     vector<int>v;
      //  int mod=1e9+7;
    
        for(auto i:queries){
            int s=i[0];
            int e=i[1];
            //string str1="";
            //if(s-1>=0)str1=pre_s[s-1];
            //int len=str1.size();
            //string str2=pre_s[e];
            //str2=str2.substr(len);
            long long a=pre_s[e];
            long long b=s-1>=0?pre_s[s-1]:0;
            long long c=pref_count[e];
            long long d=s-1>=0?pref_count[s-1]:0;
          //  if(s-1>=0)num-=pre_s[s-1];
            long long sm=pre[e];
            sm-=(s-1>=0?pre[s-1]:0);
            int len=c-d;
          // a-=(pow(10,(c-d+mod))%mod*b)%mod;
           long long num = (a - (b * pow10[len]) % mod + mod) % mod;
            v.push_back((1LL*num*sm)%mod);

        }
        return v;
    }
};