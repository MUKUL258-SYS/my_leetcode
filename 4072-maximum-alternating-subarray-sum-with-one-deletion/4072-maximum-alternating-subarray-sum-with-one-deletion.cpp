class Solution {
public:
    vector<int> nums;
    long long dp[100005][2][2];
    const long long inf = -(1LL << 60);

    long long dfs(int i, int deleted, int parity) {
        int n = nums.size();

        if (i >= n) return inf;

        if (dp[i][deleted][parity] != inf)
            return dp[i][deleted][parity];

        long long take = (parity == 0)
                       ? nums[i]
                       : -1LL * nums[i];

        long long ans = take;

        long long res = dfs(i + 1, deleted, 1 - parity);
        if (res != inf)
            ans = max(ans, take + res);

        if (!deleted) {
            long long nottake = dfs(i + 1, 1, parity);
            ans = max(ans, nottake);
        }

        return dp[i][deleted][parity] = ans;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();

        for (int i = 0; i < n; i++)
            for (int d = 0; d < 2; d++)
                for (int p = 0; p < 2; p++)
                    dp[i][d][p] = inf;

        long long ans = inf;

        for (int i = 0; i < n; i++)
            ans = max(ans, dfs(i, 0, 0));

        return ans;
    }
};