class Solution {
public:
    int minProcessingTime(vector<int>& p, vector<int>& t) {
        sort(p.begin(),p.end(),greater<int>());
        sort(t.begin(),t.end());
        int maxi=0;
        int n=t.size();
        for(int i=0;i<n;i=i+4){
            int val=p[i/4];
            int maxi2=0;
            for(int j=i;j<i+4;j++){
               maxi2=max(maxi2,val+t[j]);
            }
            maxi=max(maxi,maxi2);
        }
        return maxi;

    }
};