class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();

        if (n < 2) return 0;

        int k = n / 2;
        long long sum = 0;
        int cnt = 0;

        for (auto i : nums)
            sum += i;

        for (int i = 0; i < k - 1; i++)
            nums.push_back(nums[i]);

        long long curr_sum = 0;

        for (int i = 0; i < k; i++) {
            curr_sum += nums[i];
        }

        long long r_sum = sum - curr_sum;

        if (r_sum < curr_sum) {
            cnt++;
        }

        for (int i = 1; i < n; i++) {
            curr_sum -= nums[i - 1];
            curr_sum += nums[i + k - 1];

            r_sum = sum - curr_sum;

            if (r_sum < curr_sum) {
                cnt++;
            }
        }

        return cnt;
    }
};