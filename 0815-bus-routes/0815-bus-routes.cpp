class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<routes.size();i++){
            int bid=i;
            for(auto j:routes[i]){
                mp[j].push_back(bid);
            }
        }
        unordered_map<int,bool>bVis,bStopVis;
        queue<pair<int,int>>q;
        q.push({source,0});
        bStopVis[source]=true;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            auto p=q.front();
            int curr_stop=p.first;
            int total=p.second;
            q.pop();
            if(curr_stop==target)return total;
            for(auto i:mp[curr_stop]){
                if(bVis[i])continue;
                bVis[i]=true;
                for(auto j:routes[i]){
                    if(bStopVis[j])continue;
                    bStopVis[j]=true;
                    q.push({j,total+1});
                }
            }
        }
    }
        return -1;
    }
};