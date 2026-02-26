class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        unordered_map<long long,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(mp.count(0))continue;
                mp[0]=i;
                continue;
            }
            long long sum=0;
            for(int j=i;j<min(i+30,n);j++){
                sum=sum*2+(s[j]-'0');
                if(mp.count(sum))continue;
                mp[sum]=i;
            }
        }
     //   for(auto i:mp){
       //     cout<<i.first<<" "<<i.second<<endl;
      //  }
        vector<vector<int>>res;
        for(auto i:queries){
            long long v=(i[0]^i[1]);
            if(mp.count(v)){
        int bits = (v == 0) ? 0 : std::log2(v) + 1;
            if(bits>0)res.push_back({mp[v],mp[v]+bits-1});
            else res.push_back({mp[v],mp[v]});
            }
            else{
                res.push_back({-1,-1});
            }
        }
        return res;
    }
};