class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& vp) {
        int n=vp.size();
        sort(vp.begin(),vp.end(),[&](const auto &a,const auto &b){
            if(a[0]!=b[0])return a[0]>b[0];
            return a[1]<b[1];
        });
        int maxi=vp[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            if(vp[i][1]<maxi)cnt++;
            maxi=max(maxi,vp[i][1]);
        }
        return cnt;

    }
};