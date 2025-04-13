class Solution {
public:
    int dp[1001][1001][3];
    vector<int> sp,tp;
    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) 
                return false;
        }
        return true;
    }

    vector<int> getMaxPalindromes(const string &s) {
        int n = s.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j >= i; --j) {
                if (isPalindrome(s, i, j)) {
                    res[i] = j - i + 1;
                    break;
                }
            }
        }
        return res;
    }

    int solve(int i, int j, string &s, string &t, int f) {
        if (i >= s.size() && j >= t.size()) return 0;
        if (i >= s.size()) return tp[j];  
        if (j >= t.size()) return sp[i];
        if (dp[i][j][f] != -1) return dp[i][j][f];
        
        int res = max(sp[i], tp[j]); 
        
        if (s[i] == t[j]) {
                res = max(res, 2 + solve(i + 1, j + 1, s, t, 0));
            
        }
        
        if (f == 2) {
            int option1 = solve(i + 1, j, s, t, 2);
            int option2 = solve(i, j + 1, s, t, 2);
            res = max(res, max(option1, option2));
        }
        
        return dp[i][j][f] = res;
    }

    int longestPalindrome(string s, string t) {
        reverse(t.begin(), t.end());
        sp = getMaxPalindromes(s);
        tp = getMaxPalindromes(t);
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, t, 2);
    }
};