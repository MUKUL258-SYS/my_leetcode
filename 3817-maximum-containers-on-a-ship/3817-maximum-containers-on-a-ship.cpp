class Solution {
public:
    int maxContainers(int n, int w, int maxi) {
        int a=maxi/w;
        return min(n*n,a);
    }
};