class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
    int m = grid.size(), n = grid[0].size();
    int sr, sc, totalKeys = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            char c = grid[i][j];
            if (c == '@') sr = i, sc = j;
            if (c >= 'a' && c <= 'f') totalKeys++;
        }

    int target = (1 << totalKeys) - 1;      // e.g. 3 keys -> 111
    vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(1 << totalKeys, false)));

    queue<array<int,4>> q;                  // {row, col, mask, steps}
    q.push({sr, sc, 0, 0});
    vis[sr][sc][0] = true;

    int dr[] = {1,-1,0,0}, dc[] = {0,0,1,-1};

    while (!q.empty()) {
        auto [r, c, mask, d] = q.front(); q.pop();
        if (mask == target) return d;

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;

            char ch = grid[nr][nc];
            if (ch == '#') continue;

            int nmask = mask;
            if (ch >= 'a' && ch <= 'f')
                nmask |= (1 << (ch - 'a'));                 // pick up key
            if (ch >= 'A' && ch <= 'F' && !(mask & (1 << (ch - 'A'))))
                continue;                                    // lock, no key -> blocked

            if (vis[nr][nc][nmask]) continue;
            vis[nr][nc][nmask] = true;
            q.push({nr, nc, nmask, d + 1});
        }
    }
    return -1;
}
};