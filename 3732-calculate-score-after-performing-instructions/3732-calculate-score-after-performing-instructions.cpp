class Solution {
public:
  long long calculateScore(vector<string>& instructions, vector<int>& values) {
    long long score = 0;
    int idx = 0;
    int n = values.size();
    vector<bool> visited(n, false);

    while (idx >= 0 && idx < n && !visited[idx]) {
        visited[idx] = true;

        if (instructions[idx] == "jump") {
            idx += values[idx];
        } else {
            score += values[idx];
            idx++;
        }
    }

    return score;
}


};