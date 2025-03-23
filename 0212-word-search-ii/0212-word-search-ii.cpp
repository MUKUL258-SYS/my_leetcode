class Solution {
public:
    vector<pair<int, int>> movements = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isSafe(int x, int y, vector<vector<char>> &board) {
        int n = board.size(), m = board[0].size();
        return (x >= 0 && y >= 0 && x < n && y < m && board[x][y] != '#');
    }

    void func(int x, int y, string &curr, vector<vector<char>> &board, unordered_set<string> &st, vector<string> &ans) {
        if (curr.size() >= 10) return;
        if (!isSafe(x, y, board)) return;

        curr += board[x][y];
        if (st.find(curr) != st.end()) {
            st.erase(curr);
            ans.push_back(curr);
        }

        char ch = board[x][y];
        board[x][y] = '#';  // Mark visited

        for (auto &[dx, dy] : movements) {
            int nx = x + dx, ny = y + dy;
            func(nx, ny, curr, board, st, ans);
        }

        board[x][y] = ch;  // Unmark
        curr.pop_back();    // Correct backtracking
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> ans;
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                string curr = "";
                func(i, j, curr, board, st, ans);
            }
        }
        return ans;
    }
};
