class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        
        pq.push({grid[0][0], 0, 0}); // {time, x, y}
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        
        while (!pq.empty()) {
            int t = pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();
            if (visited[x][y]) continue;
            visited[x][y] = true;
            if (x == n-1 && y == n-1) return t;
            
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1; // Should never happen
    }
};
