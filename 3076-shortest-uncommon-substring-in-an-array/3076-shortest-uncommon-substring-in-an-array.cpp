class Solution {
public:
unordered_map<string,int>freq;
unordered_map<int,vector<pair<int,string>>>mp;
void helper(int k,string s,int idx){
    set<string>tt;
   for(int i=0;i+k<=s.size();i++){
        string temp=s.substr(i,k);
        //freq[temp]++;
        tt.insert(temp);
        mp[idx].push_back({temp.size(),temp});
        
   }
   for(auto i:tt){
    freq[i]++;
   }

}
    vector<string> shortestSubstrings(vector<string>& arr) {
      int n=arr.size();
      for(int i=0;i<n;i++){
              int m=arr[i].size();
              for(int j=1;j<=m;j++){
                helper(j,arr[i],i);
              }
      }
      vector<string>vp;
    /*  for(int i=0;i<n;i++){
        auto s=mp[i];
        for(auto j:s){
            cout<<j<<" ";
        }
        cout<<endl;
      }
      */

      vector<vector<pair<int,string>>>v;
      for(int i=0;i<n;i++){
        v.push_back(mp[i]);
      }
      for(int i=0;i<n;i++){
        sort(v[i].begin(),v[i].end(),[&](const pair<int,string>& a,const pair<int,string>&b){
            if(a.first!=b.first){
                return a.first<b.first;
            }
            return a.second<b.second;
        });
      }
     for(auto i:v){
        for(auto j:i){
            cout<<j.second<<" ";
        }
        cout<<endl;
     }
      for(int i=0;i<n;i++){
        auto s=v[i];
        bool f=false;
        for(auto j:s){
            if(freq[j.second]==1){
              vp.push_back(j.second);
              f=true;
              break;
            }
        }
        if(!f)vp.push_back("");
      }
      return vp;
    }
};