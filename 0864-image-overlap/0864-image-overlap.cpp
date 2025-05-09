class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>v1,v2;
        int n=img1.size();
        int m=img1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(img1[i][j]==1)v1.push_back({i,j});
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(img2[i][j]==1)v2.push_back({i,j});
            }
        }
        int maxi=0;
        map<pair<int,int>,int>mp;
        for(auto [x1,y1]:v1){
            for(auto [x2,y2]:v2){
                mp[{x1-x2,y1-y2}]++;
                maxi=max(maxi,mp[{x1-x2,y1-y2}]);
            }
        }
        return maxi;
    }
};