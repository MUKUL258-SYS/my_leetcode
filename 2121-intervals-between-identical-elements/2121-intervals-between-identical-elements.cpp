class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
       // vector<long long>vp();
        int n=arr.size();
        vector<long long>vp(n);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        for(auto &i:mp){
            long long sum=0;
            for(auto j:i.second){
                sum+=j;
            }
           // cout<<i.first<<" ";
           // cout<<sum<<endl;
            vector<int>v=i.second;
            long long curr_sum=0;
            int m=v.size();
            for(int k=0;k<m;k++){
               sum-=v[k];
              vp[v[k]]=1ll*v[k]*(k)-curr_sum+sum-(1ll*(m-k-1)*v[k]);
               curr_sum+=v[k];
            }
            
        }
        return vp;

    }
};