class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int cnt1=0;
        int cnt2=0;
        vector<vector<int>>v;
        for(auto &i:costs){
            vector<int>vp;
            vp.push_back(abs(i[0]-i[1]));
            vp.push_back(i[0]);
            vp.push_back(i[1]);
            v.push_back(vp);
        }
        sort(v.begin(),v.end(),[=](const vector<int>&a,const vector<int>&b){
           if(a[0]!=b[0]){
            return a[0]>b[0];
           }
           else if(a[1]!=b[1]){
            return a[1]<b[1];
           }
           return a[2]<b[2];
        });
        int n=costs.size();
        int s=0;
        for(int i=0;i<n;i++){
            if((v[i][1]<v[i][2]&&cnt1<(n/2))||cnt2==(n/2)){
               cnt1++;
               s+=v[i][1];
            }
            else {
                cnt2++;
                s+=v[i][2];
            }
        }
        return s;
    }
};