class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b,vector<int>& p, int c) {
        int n=b.size();
        int m=p.size();
        sort(b.begin(),b.end());
        sort(p.begin(),p.end());
        int j=0;
        int prev=0;
        int ans;
        for(int i=0;i<n;i++){
     int cnt=0;
     while(j<m && p[j]<=b[i] && cnt<c){
        if((p[j]-prev) > 1)ans=p[j]-1;
        prev=p[j];
        j++;
        cnt++;
     }
     if(b[i]-prev>=1 && cnt<c)ans=b[i];
        }
        return ans;

    }
};