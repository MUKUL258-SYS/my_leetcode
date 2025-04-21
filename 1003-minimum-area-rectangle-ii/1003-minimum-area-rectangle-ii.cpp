#define x1 points[i][0]
#define y1 points[i][1]
#define x2 points[j][0]
#define y2 points[j][1]
#define x3 points[k][0]
#define y3 points[k][1]
class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int ans=INT_MAX;
        int n=points.size();
        sort(points.begin(),points.end());
        set<pair<int,int>>s;
        for(auto i:points){
            s.insert({i[0],i[1]});
        }
        for(int i=0;i<n&&ans!=1;i++){
            for(int j=i+1;j<n&&ans!=1;j++){
                for(int k=j+1;k<n&&ans!=1;k++){
                    if((x1-x2)*(x2-x3)+(y1-y2)*(y2-y3)==0&&s.count({x1+x3-x2,{y1+y3-y2}})){
                        ans=min(ans,abs((x1-x2)*(y2-y3)-(y1-y2)*(x2-x3)));
                    }
                }
            }
        }
        return ans==INT_MAX?0.0:double(ans);
    }
};