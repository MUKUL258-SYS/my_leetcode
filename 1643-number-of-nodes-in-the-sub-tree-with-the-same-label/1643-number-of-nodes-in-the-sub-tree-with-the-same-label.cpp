class Solution {
public:
    unordered_map<int, vector<int>> adj; // Use unordered_map to save memory
    vector<int> ans;
    vector<vector<int>> freq; // Global storage to avoid excessive recursion memory

    void dfs(int node, int parent, string &labels) {
        freq[node][labels[node] - 'a']++; // Count the current node's label

        for (int nei : adj[node]) {
            if (nei == parent) continue; // Avoid revisiting the parent
            dfs(nei, node, labels);
            // Merge child frequency into the current node's frequency
            for (int i = 0; i < 26; i++) {
                freq[node][i] += freq[nei][i];
            }
        }
        ans[node] = freq[node][labels[node] - 'a']; // Store answer for this node
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n, 0);
        freq.assign(n, vector<int>(26, 0)); // Preallocate memory
        
        // Build an undirected graph using unordered_map to reduce memory overhead
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        dfs(0, -1, labels); // Start DFS from root node 0
        return ans;
    }
};
