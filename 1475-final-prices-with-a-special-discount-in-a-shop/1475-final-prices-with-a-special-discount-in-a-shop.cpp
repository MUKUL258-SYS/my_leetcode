class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int,int>>s;
        
        int n=prices.size();
       // vector<int>v(n);
        for(int i=0;i<n;i++){
            while(!s.empty()&&prices[i]<=s.top().first){
                int idx=s.top().second;
                prices[idx]-=prices[i];
                s.pop();
            }
            s.push({prices[i],i});
        }
        return prices;
    }
};