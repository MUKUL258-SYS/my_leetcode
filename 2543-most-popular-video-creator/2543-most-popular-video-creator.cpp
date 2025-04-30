class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
           unordered_map<string,long long>mp;
           int n=views.size();
           long long maxi=0;
           for(int i=0;i<n;i++){
            mp[creators[i]]+=views[i];
           }
           map<string,pair<long long,string>>mp2;
           for(int i=0;i<n;i++){
                string c=creators[i];
                long long v=views[i];
                string id=ids[i];
                if(mp2.find(c)==mp2.end()||v>mp2[c].first||v==mp2[c].first&&id<mp2[c].second)mp2[c]={v,id};
           }
           for(auto i:mp){
            maxi=max(maxi,i.second);
           }
         vector<vector<string>>v;
          for(auto i:mp){
            if(i.second==maxi){
                  v.push_back({i.first,mp2[i.first].second});
            }
          }
          sort(v.begin(),v.end());
          return v;
    } 
};