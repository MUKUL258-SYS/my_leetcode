class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](const vector<int>&a,const vector<int>&b){
           if(a[0]!=b[0])return a[0]>b[0];
           return a[1]<b[1];
        });
        int n=p.size();
        int ans=0;
        for(int i=0;i+1<n;i++){
            int y=INT_MAX;
            for(int j=i+1;j<n;j++){
              if((p[i][1]<=p[j][1])&&p[j][1]<y){
                ans++;
                y=p[j][1];
                if(p[i][1]==p[j][1])break;
              }
            }
        }
        return ans;
    }
};