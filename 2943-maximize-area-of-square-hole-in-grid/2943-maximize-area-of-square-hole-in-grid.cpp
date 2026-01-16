class Solution {
public:
int maxGap(vector<int>&v){
    sort(v.begin(),v.end());
    int maxi=1;
    int g=1;
    for(int i=1;i<v.size();i++){
       if((v[i]-v[i-1])==1){
        g++;
       }
       else{
      //  maxi=max(maxi,g);
        g=1;
       }
       maxi=max(maxi,g);
    }
    return maxi+1;
}
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
       int v= min(maxGap(hBars),maxGap(vBars));
       return v*v;
    }
};