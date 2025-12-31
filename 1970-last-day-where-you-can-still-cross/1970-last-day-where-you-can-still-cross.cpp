class Solution {
public:
    int r, c;

    int dfs(int i, int j,
            vector<vector<int>>& grid,
            vector<vector<int>>& dp,
            vector<vector<int>>& vis) {

        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 1) return 0;
        if (i == r - 1) return 1;                 // reached bottom
        if (dp[i][j] != -1) return dp[i][j];
        if (vis[i][j]) return 0;                  // prevent cycles
        vis[i][j] = 1;

        int a  = dfs(i + 1, j, grid, dp, vis);
        int b  = dfs(i - 1, j, grid, dp, vis);    // you missed this
        int ce = dfs(i, j + 1, grid, dp, vis);
        int d  = dfs(i, j - 1, grid, dp, vis);

        vis[i][j] = 0;                            // backtrack

        return dp[i][j] = (a || b || ce || d);
    }

    bool helper(int mid, vector<vector<int>>& cells) {
        vector<vector<int>> grid(r, vector<int>(c, 0));
        for (int i = 0; i <= mid; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        vector<vector<int>> dp(r, vector<int>(c, -1));
        vector<vector<int>> vis(r, vector<int>(c, 0));

        for (int j = 0; j < c; j++) {
            if (grid[0][j] == 0 && dfs(0, j, grid, dp, vis)) return true;
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        r = row;
        c = col;

        int n = (int)cells.size();
        int s = 0, e = n - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (helper(mid, cells)) {
                ans = mid;        // FIX: store mid
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans + 1;
    }
};
