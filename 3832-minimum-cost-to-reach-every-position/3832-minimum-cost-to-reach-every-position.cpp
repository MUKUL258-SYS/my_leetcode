class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int n=cost.size();
        vector<int>vp(n);
        vp[0]=cost[0];
        for(int i=1;i<n;i++){
            vp[i]=min(vp[i-1],cost[i]);
        }
        return vp;
    }
};