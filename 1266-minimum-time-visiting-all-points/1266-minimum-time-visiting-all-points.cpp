class Solution {
public:
int helper(vector<int>&v1,vector<int>&v2){
    int diffx=abs(v1[0]-v2[0]);
    int diffy=abs(v1[1]-v2[1]);
    return max(diffx,diffy);
}
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i+1<n;i++){
         ans+=helper(points[i],points[i+1]);
        }
        return ans;
    }
};