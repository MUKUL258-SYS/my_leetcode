class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
       // priority_queue<pair<int,int>>pq;
       set<pair<int,int>>s;
        vector<bool>vis(n,false);
        long long total=0;
        for(int i=0;i<n;i++){
            s.insert({nums[i],i});
            total+=nums[i];
        }
     vector<long long>vp;
        for(auto i:queries){
            int idx=i[0];
            int cnt=i[1];
            if(!vis[idx]){
              vis[idx]=true;
              s.erase({nums[idx],idx});
              total-=nums[idx];
            }
            auto itr=s.begin();
            while(itr!=s.end()&&(cnt--)){
                 idx=itr->second;
                vis[idx]=true;
                s.erase({nums[idx],idx});
                total-=nums[idx];
                itr++;
            }
            vp.push_back(total);
        }
        return vp;
    }
};