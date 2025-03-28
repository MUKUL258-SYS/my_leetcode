class Solution {
public:
struct State{
    int mask,node,dist;
};
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int maxsize=(1<<n)-1;
        queue<State>q;
        unordered_set<int>vis;

        for(int i=0;i<n;i++){
            q.push({1<<i,i,0});
            vis.insert((1<<i)*16+i);
        }
        while(!q.empty()){
            State f=q.front();
            q.pop();
            if(f.mask==maxsize)return f.dist;
            for(auto nei:graph[f.node]){
               int new_mask=(f.mask)|(1<<nei);
               int h_value=new_mask*16+nei;
               if(vis.find(h_value)==vis.end()){
                    q.push({new_mask,nei,f.dist+1});
                    vis.insert(h_value);
               }
            }
        }
        return -1;
    }
};