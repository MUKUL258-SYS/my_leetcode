class Solution {
public:
    int mod = 1e9 + 7;
    int limit;
    int dp[201][201][2];

    long long solve(int z, int o, int last) {
        if (z == 0 && o == 0) return 1;
        if (dp[z][o][last] != -1) return dp[z][o][last];

        long long ans = 0;
        if (last == 1) { // Last was 1, must place 0s now
            for (int i = 1; i <= min(z, limit); ++i) {
                ans = (ans + solve(z - i, o, 0)) % mod;
            }
        } else { // Last was 0, must place 1s now
            for (int i = 1; i <= min(o, limit); ++i) {
                ans = (ans + solve(z, o - i, 1)) % mod;
            }
        }

        return dp[z][o][last] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        this->limit = limit;
        memset(dp, -1, sizeof(dp));
        // We can start by placing either a block of 0s or a block of 1s
        // We pass 'last' as the opposite to trigger the initial loops
        return (solve(zero, one, 0) + solve(zero, one, 1)) % mod;
    }
};