class Solution {
public:
 vector<vector<int>>helper(vector<vector<int>>&vp){
    sort(vp.begin(),vp.end());
    if(vp.size()<=1)return vp;
    vector<vector<int>>merged;
    int n=vp.size();
    merged.push_back(vp[0]);
    for(int i=1;i<n;i++){
       if(vp[i][0]>=merged.back()[1]){
        merged.push_back(vp[i]);
       }
       else{
        merged.back()[1]=max(merged.back()[1],vp[i][1]);
       }
    }
    return merged;
 }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>x,y;
        for(auto i:rectangles){
            x.push_back({i[0],i[2]});
            y.push_back({i[1],i[3]});
        }
        vector<vector<int>>a=helper(x);
        vector<vector<int>>b=helper(y);
        if(a.size()>=3||b.size()>=3)return true;
        else return false;

    }
};