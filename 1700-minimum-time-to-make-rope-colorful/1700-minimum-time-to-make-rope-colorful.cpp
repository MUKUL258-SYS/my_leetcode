class Solution {
public:
    int minCost(string colors, vector<int>& nTime) {
     int n=colors.size();
     int maxi=nTime[0];
     int total_cost=nTime[0];
     int res=0;
     for(int i=1;i<n;i++){
        if(colors[i]==colors[i-1]){
             maxi=max(maxi,nTime[i]);
             total_cost+=nTime[i];
        }
        else{
            res+=(total_cost-maxi);
            maxi=nTime[i];
            total_cost=nTime[i];
        }
     }
        res+=(total_cost-maxi);
     return res;   
    }
};