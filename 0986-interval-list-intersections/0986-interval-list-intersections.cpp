class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& vp1, vector<vector<int>>& vp2) {
        vector<vector<int>>v;
        for(int i=0,j=0;i<vp1.size()&&j<vp2.size();){
           int lo=max(vp1[i][0],vp2[j][0]);
           int hi=min(vp1[i][1],vp2[j][1]);
           if(lo<=hi)v.push_back({lo,hi});
           if(hi==vp2[j][1])j++;
           else i++;
        }
        return v;
    }
};