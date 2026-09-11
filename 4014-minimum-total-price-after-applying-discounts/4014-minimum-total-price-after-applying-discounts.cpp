class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& d) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(d.begin(),d.end(),greater<int>());
        
        int mini=min(prices.size(),d.size());
        double res=0;
        for(int i=0;i<mini;i++){
          res=res+(prices[i]*(100-d[i])/100.00000);
        }
        for(int i=mini;i<prices.size();i++)res+=prices[i];
        return res;
    }
};