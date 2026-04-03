#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
    int memo[12][1 << 12]; // N is at most 12 for this problem

    int dfs(int node, int mask, vector<vector<int>>& graph) {
        // Base Case: If only one bit is set, the distance is 0
        if ((mask & (mask - 1)) == 0) {
            return 0;
        }

        // Return cached result if already calculated
        if (memo[node][mask] != -1) {
            return memo[node][mask];
        }

        // Initialize with a large value to avoid cycles
        memo[node][mask] = 1e9;

        for (int neighbor : graph[node]) {
            if (mask & (1 << neighbor)) {
                // If neighbor is already in the mask, we check two paths:
                // 1. Moving to neighbor without changing the mask
                int visited = 1 + dfs(neighbor, mask, graph);
                
                // 2. Moving to neighbor assuming 'node' was the most recently added 
                //    (backtracking the mask)
                int notVisited = 1 + dfs(neighbor, mask ^ (1 << node), graph);

                memo[node][mask] = min({memo[node][mask], visited, notVisited});
            }
        }

        return memo[node][mask];
    }

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int endingMask = (1 << n) - 1;
        
        // Initialize memo table with -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= endingMask; j++) {
                memo[i][j] = -1;
            }
        }

        int minPath = 1e9;
        for (int i = 0; i < n; i++) {
            minPath = min(minPath, dfs(i, endingMask, graph));
        }

        return minPath;
    }
};