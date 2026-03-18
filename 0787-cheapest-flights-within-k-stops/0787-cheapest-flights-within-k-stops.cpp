class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src,0});
        vector<vector<pair<int,int>>>gr(n);
        for(auto i:flights){
            gr[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dp(n,INT_MAX);

        //{dist,node,steps};
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            int dist=t[0];
            int node=t[1];
            int steps=t[2];
            if(steps>=dp[node]||steps>k+1)continue;
            dp[node]=steps;
            if(node==dst)return dist;
            for(auto [nei,cost]:gr[node]){
                pq.push({dist+cost,nei,steps+1});
            }


        }
        return -1;
    }
};