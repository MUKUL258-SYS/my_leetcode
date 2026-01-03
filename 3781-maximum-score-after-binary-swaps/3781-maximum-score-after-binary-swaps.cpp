class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
    long long sum = 0;
    int n = s.size();

    // 1) remove trailing 0's
    while (n > 0 && s[n - 1] == '0') {
        n--;
    }

    int i = 0;

    // 2) take mandatory leading 1's
    while (i < n && s[i] == '1') {
        sum += nums[i];
        i++;
    }

    // 3) greedy over remaining part
    priority_queue<int>pq;
    for (; i < n; i++) {
       // maxi = max(maxi, nums[i]);   // collect best so far
pq.push(nums[i]);
        if (s[i] == '1') {           // forced pick
            sum += pq.top();
            pq.pop();
        }
    }

    return sum;
}

};