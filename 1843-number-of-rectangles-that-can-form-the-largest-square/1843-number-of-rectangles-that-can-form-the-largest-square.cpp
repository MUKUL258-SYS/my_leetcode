class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int>mp;
        int maxi=0;
        for(auto i:rectangles){
            int m=min(i[0],i[1]);
            mp[m]++;
            maxi=max(maxi,m);
        }
        return mp[maxi];

    }
};