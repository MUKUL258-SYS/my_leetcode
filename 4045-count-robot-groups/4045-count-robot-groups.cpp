class Solution {
public:
    int countGroups(vector<int>&p,vector<int>&s,int dist) {
        int g=1;
        int n=p.size();
        int c_speed=s[n-1];
        for(int i=n-2;i>=0;i--){
            if(p[i+1]-p[i] <= dist || (s[i]>c_speed)){
                continue;
            }
            g++;
            c_speed=s[i];
            
        }
        return g;
    }
};