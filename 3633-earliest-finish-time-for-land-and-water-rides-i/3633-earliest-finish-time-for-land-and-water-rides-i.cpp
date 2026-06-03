class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n=ls.size();
        int m=ws.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int e1=ls[i]+ld[i];
            for(int j=0;j<m;j++){
                //int e2=ws[j]+wd[j];
                if(e1>=ws[j]){
                    mini=min(mini,e1+wd[j]);
                }
                else{
                    mini=min(mini,ws[j]+wd[j]);
                }
            }
        }
        for(int i=0;i<m;i++){
            int e1=ws[i]+wd[i];
            for(int j=0;j<n;j++){
                //int e2=ws[j]+wd[j];
                if(e1>=ls[j]){
                    mini=min(mini,e1+ld[j]);
                }
                else{
                    mini=min(mini,ls[j]+ld[j]);
                }
            }
        }
        return mini;
    }
};