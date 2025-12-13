class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        if(n==1)return 0;
        unordered_map<int,vector<pair<int,pair<int,int>>>>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i:edges){
            mp[i[0]].push_back({i[1],{i[2],i[3]}});
        }
        ///pq{currenttime,node}
        vector<int>time(n,INT_MAX);
        pq.push({0,0});
        while(!pq.empty()){
            int t=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(t>=time[node])continue;
            time[node]=t;
            //int temp=t;
            for(auto j:mp[node]){
                 int temp=t;
                auto nei=j.first;
                auto st=j.second.first;
                auto et=j.second.second;
                if(temp>et)continue;
                if(temp<st)temp=st;
                temp++;
                pq.push({temp,nei});
            }
        }
        return time[n-1]==INT_MAX?-1:time[n-1];

        
    }
};