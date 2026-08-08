class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int>ans(n,-1);
        vector<vector<pair<int,int>>>adj(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        ans[0]=0;
        while(!pq.empty()){
            auto [dis,node]=pq.top();
            pq.pop();
            if(dis>ans[node])continue;
            for(auto [nei,wt]:adj[node]){
                int td=wt+dis;
                if(td<disappear[nei] &&(ans[nei]==-1 || td<ans[nei])){
                    pq.push({td,nei});
                    ans[nei]=td;
                }
            }
        }
        return ans;
    }
};