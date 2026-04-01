class Solution {
public:

    // DFS-based Topological Sort
    /*bool dfsTopo(int node,
                 vector<unordered_set<int>>& adj,
                 vector<int>& state,
                 vector<int>& topo) {
        
        if (state[node] == 1) return false;   // cycle
        if (state[node] == 2) return true;    // already processed

        state[node] = 1; // visiting

        for (int neighbor : adj[node]) {
            if (!dfsTopo(neighbor, adj, state, topo))
                return false;
        }

        state[node] = 2; // visited
        topo.push_back(node);
        return true;
    }*/
    bool topoDfs(int node,vector<unordered_set<int>>&adj,vector<int>&state,vector<int>&topo){
        if(state[node]==1)return false;
        if(state[node]==2)return true;
        state[node]=1;
        for(auto nei:adj[node]){
            if(!topoDfs(nei,adj,state,topo))return false;
        }
        state[node]=2;
        topo.push_back(node);
        return true;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        int totalNodes = n + 2 * m;

        vector<unordered_set<int>> adj(totalNodes);
        vector<int> state(totalNodes, 0);  // 0=unvisited,1=visiting,2=visited
        vector<int> topoOrder;

        // 🔹 Step 1: Build Graph
        /*for (int i = 0; i < n; i++) {

            // Case 1: Item belongs to a group
            if (group[i] != -1) {
                int groupStart = n + group[i];
                int groupEnd   = n + m + group[i];

                adj[groupStart].insert(i);   // groupStart → item
                adj[i].insert(groupEnd);     // item → groupEnd
            }

            // Case 2: Dependencies
            for (int prev : beforeItems[i]) {

                if (group[i] != -1 && group[i] == group[prev]) {
                    // Same group → direct dependency
                    adj[prev].insert(i);
                } else {
                    // Different groups → connect via group nodes

                    int from = (group[prev] == -1) ? prev : n + m + group[prev];
                    int to   = (group[i] == -1)   ? i    : n + group[i];

                    adj[from].insert(to);
                }
            }
        }
    */
    for(int i=0;i<n;i++){
        if(group[i]!=-1){
            int groupStart=group[i]+n;
            int groupEnd=group[i]+n+m;
            adj[groupStart].insert(i);
            adj[i].insert(groupEnd);
        }
        for(auto prev:beforeItems[i]){
            if(group[i]!=-1&&group[i]==group[prev]){
                adj[prev].insert(i);
            }
            else{
                int from=group[prev]==-1?prev:n+m+group[prev];
                int to=group[i]==-1?i:n+group[i];
                adj[from].insert(to);
            }
        }
    }
        // 🔹 Step 2: Topological Sort
        for (int node = totalNodes - 1; node >= 0; node--) {
            if (state[node] == 0) {
                if (!topoDfs(node, adj, state, topoOrder))
                    return {}; // cycle found
            }
        }

        reverse(topoOrder.begin(), topoOrder.end());

        // 🔹 Step 3: Extract only item nodes (ignore group nodes)
        vector<int> result;
        for (int node : topoOrder) {
            if (node < n)
                result.push_back(node);
        }

        return result;
    }
};