class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        vector<pair<int,int>>vp;
        int n=t1.size();
        for(int i=0;i<n;i++){
            vp.push_back({t1[i]-t2[i],i});
        }
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
unordered_map<int,int>mp;
long long sum=0;
for(auto i:vp){
    if(mp.size()==k)break;
   // cout<<t1[i.second]<<" ";
    sum+=t1[i.second];
    mp[i.second]++;
}
//sort(t1.begin(),t1.end(),greater<int>());
//sort(t2.begin(),t2.end(),greater<int>());
/*vector<pair<int,int>>v1,v2;
for(int i=0;i<n;i++){
    v1.push_back({t1[i],i});
    v2.push_back({t2[i],i});
}
sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());
reverse(v1.begin(),v1.end());
reverse(v2.begin(),v2.end());
for(int i=0;i<n;i++){
    int idx1=v1[i].second;
    int idx2=v2[i].second;
    if(idx1==idx2&&mp[idx1]==0){
        sum+=max(v1[i].first,v2[i].first);
        mp[idx1]++;
        continue;
    }
    if(mp[idx1]==0){
         sum+=v1[i].first;
          mp[idx1]++;
        
    }
    if(mp[idx2]==0){
         sum+=v2[i].first;
          mp[idx2]++;
        
    }
 */
 for(int i=0;i<n;i++){
    if(mp[i]>0)continue;
    sum+=max(t1[i],t2[i]);
    mp[i]++;
 }  
return sum;
    }
};