class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        for(int i=0;i<units.size();i++){
            sort(units[i].begin(),units[i].end());
        }
        sort(units.begin(),units.end());
       /* sort(units.begin(), units.end(), [](const vector<int>& a, const vector<int>& b) {
    return a.back() > b.back(); // Puts devices with larger max units first
});
*/
        int m=units[0].size();
        if(m==1){
            long long r=0;
            for(auto i:units)r+=i[0];
            return r;
        }
        int n=units.size();
        long long sum=0;
        int j=-1;
        int mini=INT_MAX;
        int mini2=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=units[i][1];
           mini=min(mini,units[i][0]);
           mini2=min(mini2,units[i][1]);

           // mini=min(mini,units[i][1]-units[i][0]);
        }
        
        return sum-(mini2-mini);

    }
};