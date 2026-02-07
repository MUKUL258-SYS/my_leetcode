class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int>s(forbidden.begin(),forbidden.end());
        queue<pair<pair<int,bool>,int>>q;
        vector<vector<bool>>vis(6002,vector<bool>(2,false));
        vis[0][0]=true;
        q.push({{0,false},0});
        while(!q.empty()){
            auto node=q.front().first.first;
            auto jumpedBack=q.front().first.second;
            auto steps=q.front().second;
            q.pop();
            if(node==x)return steps;
            int curr=node+a;
            if(curr<=6000&&!vis[curr][0]&&!s.count(curr)){
               q.push({{curr,0},steps+1});
               vis[curr][0]=true;   
            }
            curr=node-b;
            if(!jumpedBack&&(curr>=0)&&!vis[curr][1]&&!s.count(curr)){
                q.push({{curr,1},steps+1});
                vis[curr][1]=true;
            }
        }
        return -1;
    }
};